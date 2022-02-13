#include <string>
#include <vector>
#include <unordered_map>

class FileSystem {
  class FileDirectory {
    string name;
    string content;
    unordered_map<string, FileDirectory*> sub_dirs;
  public:
    FileDirectory(string name) : name(name), content("") {}
  
    void setContent(string c) { content += c; }
  
    string getContent() {return content;}
  
    FileDirectory* addSubDir(string sub_name) {
      // add the subdirectory if it's not existing
      if (sub_dirs.find(sub_name) == sub_dirs.end()) sub_dirs[sub_name] = new FileDirectory(sub_name);
      return sub_dirs[sub_name];
    }
  
    vector<string> list_dir() {
      // if we have some content, that means this is a file, just return its name
      if (!content.empty()) return vector<string>({name});
      // otherwise we scan the sub-directories
      vector<string> result;
      for (auto& [f_name, dir_ptr] : sub_dirs) result.push_back(f_name);
      // and the sort them lexicographically
      sort(result.begin(), result.end());
      return result;
    }
  };
  
  FileDirectory* root;
  
  // get down to the lowest layer of path
  FileDirectory* pathResolver(string path) {
    FileDirectory* f = root;
    string dir;
    // skip the first / by starting at the second character
    for (int i = 1; i < path.size(); i++) {
      // we encounter the end of a dir name
      // go down one layer
      if (path[i] == '/') {
        f = f->addSubDir(dir);
        dir.clear();
      }
      // otherwise append the character to dir
      else dir.push_back(path[i]);
    }
    // if the path doesn't end with /, we have one more layer to go down
    if (!dir.empty()) f = f->addSubDir(dir);
    return f;
  }
  
public:
  FileSystem() {
    root = new FileDirectory("root");
  }
    
  vector<string> ls(string path) {
    return pathResolver(path)->list_dir();
  }
    
  void mkdir(string path) {
    pathResolver(path);
  }
    
  void addContentToFile(string filePath, string content) {
    pathResolver(filePath)->setContent(content);
  }
    
  string readContentFromFile(string filePath) {
    return pathResolver(filePath)->getContent();
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

class FileDirectory:
  def __init__(self, name: str):
    self.name = name
    self.content = ""
    self.sub_dirs = {}
    
  def addContent(self, c: str) -> None:
    self.content += c
      
  def getContent(self) -> str:
    return self.content
    
  def addSubDir(self, sub_name: str):
    sub_dir = self.sub_dirs.get(sub_name)
    if not sub_dir:
      self.sub_dirs[sub_name] = FileDirectory(sub_name)
    return self.sub_dirs[sub_name]
    
  def list_dir(self) -> List[str]:
    if self.content:
      return [self.name]
    return sorted(self.sub_dirs.keys())

class FileSystem:
  
  def __init__(self):
    self.root = FileDirectory("root")

  def ls(self, path: str) -> List[str]:
    return self.pathResolver(path).list_dir()

  def mkdir(self, path: str) -> None:
    self.pathResolver(path)

  def addContentToFile(self, filePath: str, content: str) -> None:
    self.pathResolver(filePath).addContent(content)

  def readContentFromFile(self, filePath: str) -> str:
    return self.pathResolver(filePath).getContent()

  def pathResolver(self, path: str) -> FileDirectory:
    layers = path.split('/')[1:]
    if not layers[-1]:
      layers = layers[:-1]
    d = self.root
    for layer in layers:
      d = d.addSubDir(layer)
    return d

# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)

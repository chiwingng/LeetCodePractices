# 588. Design In-Memory File System

LeetCode Problem Link: <https://leetcode.com/problems/design-in-memory-file-system/>

## Description

Design a data structure that simulates an in-memory file system.

Implement the FileSystem class:

- `FileSystem()` Initializes the object of the system.
- `List<String> ls(String path)`
   - If path is a file path, returns a list that only contains this file's name.
   - If path is a directory path, returns the list of file and directory names **in this directory**.
   - The answer should in **lexicographic order**.
- `void mkdir(String path)` Makes a new directory according to the given `path`. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.
- `void addContentToFile(String filePath, String content)`
   - If `filePath` does not exist, creates that file containing given `content`.
   - If `filePath` already exists, appends the given `content` to original content.
- `String readContentFromFile(String filePath)` Returns the content in the file at `filePath`.

## Solution Thoughts

### Observations and Logic
- There is no need to separately store files and directories, simply accessing `content` will tell.
- For all functions to work, they all need to follow the paths to the lowest layer, then perform their actions.
- All files/directories should support functions: `ls`, `addSubDir`, `addContent` and `readContent`.
- Since all directories are valid while accessing, we don't need to check for the mode of access (read/write) and raise error when accessing invalid paths.

## Constraints

- `1 <= path.length, filePath.length <= 100`
- `path` and `filePath` are absolute paths which begin with `'/'` and do not end with `'/'` except that the path is just `"/"`.
- You can assume that all directory names and file names only contain lowercase letters, and the same names will not exist in the same directory.
- You can assume that all operations will be passed valid parameters, and users will not attempt to retrieve file content or list a directory or file that does not exist.
- `1 <= content.length <= 50`
- At most 300 calls will be made to `ls`, `mkdir`, `addContentToFile`, and `readContentFromFile`.

## Examples

### Example 1

> **Input**
>
> ["FileSystem", "ls", "mkdir", "addContentToFile", "ls", "readContentFromFile"]
>
> [[], ["/"], ["/a/b/c"], ["/a/b/c/d", "hello"], ["/"], ["/a/b/c/d"]]
>
> **Output**
>
> [null, [], null, null, ["a"], "hello"]
>
>
>
> **Explanation**
>
> FileSystem fileSystem = new FileSystem();
>
> fileSystem.ls("/");                         // return []
>
> fileSystem.mkdir("/a/b/c");
>
> fileSystem.addContentToFile("/a/b/c/d", "hello");
>
> fileSystem.ls("/");                         // return ["a"]
>
> fileSystem.readContentFromFile("/a/b/c/d"); // return "hello"

| Operation | Output | Explanation |
| --- | --- | --- |
| `FileSystem fs = new FileSystem()` | null | The constructor returns nothing. |
| `fs.ls("/")` | [] | Initially, directory `/` has nothing. So return empty |
| `fs.mkdir("/a/b/c")` | null | Create directory `a` in directory `/` . Then create directory `b` in directory `a` . Finally, create directory `c` in directory `b`. |
| `fs.addContentToFile("/a/b/c/d","hello")` | null | Create a file named `d` with content `"hello"` in directory `/a/b/c`. |
| `fs.ls("/')` | ["a"] | Only directory `a` is in directory `/` |
| `fs.readContentFromFile("/a/b/c/d")` | "hello" | Output the file content. |

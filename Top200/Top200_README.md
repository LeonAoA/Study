# Top200
This will contain some of what I want to learn

gci -Recurse -Filter *2024*.md | Select-Object FullName

##  1. 2024.09

gci -Recurse -Filter *2409*.md | Select-Object FullName

1. 01、无重复字符的最长子串（20240911，3题，中等） DoublePoint 

2. 01、最长回文子串（20240912，5题，中等。28min） DynamicProgramming

3. 01、LRU 缓存（20240919，146题，中等） List 
   
4. 02、两数相加（20240920，2题，中等。32min） List 

5. 02、盛最多水的容器（20240920，11题，中等。41min） DoublePoint 

6. 01、岛屿数量（20240920，200题，中等。49min） GraphTheory 

7. 01、字母异位词分组（20240923，49题，中等。89min） String 

8. 01、螺旋矩阵（20240924，54题，中等。25min） Arrays 

9.  01、最长连续序列（20240924，128题，中等） HashTable 

10. 01、数组中的第K个最大元素（20240925，215题，中等，18min） Sorting

##  2. 2024.10

gci -Recurse -Filter *2410*.md | Select-Object FullName

1. 01、括号生成（20241002，22题，中等） 08_BackTracking
   
2. 02、和为 K 的子数组（20241004，560题，中等） 03_HashTable

3. 02、旋转图像（20241005，48题，中等）  01_Arrays

4. 02、整数反转（20241009，7题，中等）  04_String

5. 03、字符串相乘（20241009，43题，中等）  04_String  官方答案待补充！

6. 02、在排序数组中查找元素的第一个和最后一个位置（20241009，34题，中等。50min）  13_Sorting  官方答案待补充！

7. 03、删除有序数组中的重复项 II（20241010，80题，中等。15min） 05_DoublePoint

8. 03、反转链表 II（20241010，92题，中等。25min） 02_List 官方答案待补充！

9. 01、字符串解码（20241015，394题，中等）  06_StackAndQueue  还有第二种解法！

10. 03、排序数组（20241015，912题，中等，45min）  13_Sorting  答案有多重排序方法，学学。用ChatGPT看能否优化自己代码，以及看下复杂度

11. 01、最大数（20241016，179题，中等）  09贪心

12. 04、搜索旋转排序数组（20241016，33题，中等）  13_Sorting  还要看下答案！！！

13. 04、找到字符串中所有字母异位词（20241017，438题，中等）  05_DoublePoint

14. 04、搜索旋转排序数组（20241016，33题，中等）  13_Sorting  


---

![alt text](200image/d0e8677d840ab43a25ccb6663aa46656.jpg)

240题
![alt text](200image/39f44236ee8b767772f4143c7b0fe50f.jpg)
![alt text](200image/54daa0fbadeaf6edb27ce5b78d7ad859.jpg)
![alt text](200image/1bf6e8020cf6b1e661bcda6a07a3b510.jpg)
![alt text](200image/153c9e50adea64062caa137d8daf0c75.jpg)
![alt text](200image/acdc4171b4627907e4f6c533e032d431.jpg)
![alt text](200image/0146a01202ab3665335689289f0712e5.jpg)
![alt text](200image/5a2c80bbce0c2c8a0e7e60934d886e72.jpg)
![alt text](200image/d2957a5b443ae548754595c4a359837d.jpg)
![alt text](200image/0dba39acd24a25702556abe56f16ee83.jpg)

---

![alt text](200image/ccd237de8cf7ca7b5acc4bb5acdfff63.jpg)
![alt text](200image/336258218ad00cf88c9dc990398c1bff.jpg)
![alt text](200image/d9bd1ee6dc9ebdd3bab1670df3c1d85f.jpg)
![alt text](200image/be1c48386d244c273e3520527fbdf752.jpg)

---

![alt text](200image/ffdd4b681ac5de63ac9d6ab8662a9c36.jpg)
![alt text](200image/712e5db3b10ba572515d7ee474c41d3f.jpg)
![alt text](200image/9f3674897332304da0a7e6a29c183c0a.jpg)
![alt text](200image/a81ef80498ed328981ddf32b4aabdd64.jpg)
以下是对这个问题的分析和解决方法：


**一、错误分析**：
- **文件或目录不存在**：
    - 错误信息 `cc1plus.exe: fatal error: D:\BaiduSyncdisk/2-面试搜集信息: No such file or directory` 表明编译器在编译过程中试图访问一个不存在的文件或目录。这可能是由于包含目录路径错误或者文件确实不存在。
    - 从编译器命令 `C:/MinGW/bin/g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference --std=gnu++14 -g3 -O0 -ID:\BaiduSyncdisk/** -c d:\BaiduSyncdisk\Study_github\Study\test_code\test0108.cpp -o.\build\Debug\test0108.o` 来看，可能是 `-ID:\BaiduSyncdisk/**` 这个包含目录的设置有问题，其中的 `**` 通配符可能导致编译器尝试访问一个不存在的子目录或文件。


**二、解决方法**：

**1. 检查包含目录**：
- **情况一：错误的通配符使用**：
    - 如果你不需要 `-ID:\BaiduSyncdisk/**` 这个包含目录，可以直接从编译器命令中删除它，因为它可能是多余的，或者错误地添加了通配符。
    - 修改 `tasks.json` 中的 `args` 部分，删除 `-ID:\BaiduSyncdisk/**`：
        ```json
        {
            "version": "2.0.0",
            "tasks": [
                {
                    "label": "C/C++: g++.exe build active file",
                    "type": "shell",
                    "command": "g++",
                    "args": [
                        "-Wall",
                        "-Wextra",
                        "-Wpedantic",
                        "-Wshadow",
                        "-Wformat=2",
                        "-Wcast-align",
                        "-Wconversion",
                        "-Wsign-conversion",
                        "-Wnull-dereference",
                        "--std=gnu++14",
                        "-g3",
                        "-O0",
                        "-c",
                        "${file}",
                        "-o",
                        "${fileDirname}/build/Debug/${fileBasenameNoExtension}.o",
                        "&&",
                        "C:/MinGW/bin/g++",
                        "-Wall",
                        "-Wextra",
                        "-Wpedantic",
                        "-Wshadow",
                        "-Wformat=2",
                        "-Wcast-align",
                        "-Wconversion",
                        "-Wsign-conversion",
                        "-Wnull-dereference",
                        "--std=gnu++14",
                        "-g3",
                        "-O0",
                        "${fileDirname}/build/Debug/${fileBasenameNoExtension}.o",
                        "-o",
                        "${fileDirname}/build/Debug/outDebug.exe"
                    ],
                    "options": {
                        "cwd": "${workspaceFolder}"
                    },
                    "problemMatcher": [
                        "$gcc"
                    ],
                    "group": "build",
                    "detail": "编译器: g++"
                }
            ]
        }
        ```


**2. 确认文件和目录存在**：
- **情况二：检查文件路径**：
    - 确保 `D:\BaiduSyncdisk\Study_github\Study\test_code\test0108.cpp` 这个文件确实存在，并且有足够的权限访问它。
    - 如果你有自定义的头文件在 `D:\BaiduSyncdisk` 或其子目录中，确保路径正确，避免使用通配符，除非你确实知道你在做什么。


**3. 检查工作区和项目结构**：
- 确认你的项目结构和文件系统布局与编译器命令中的路径匹配，特别是涉及到的包含目录和源文件路径。


**三、修改后代码示例（tasks.json）**：
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "C/C++: g++.exe build active file",
            "type": "shell",
            "command": "g++",
            "args": [
                "-Wall",
                "-Wextra",
                "-Wpedantic",
                "-Wshadow",
                "-Wformat=2",
                "-Wcast-align",
                "-Wconversion",
                "-Wsign-conversion",
                "-Wnull-dereference",
                "--std=gnu++14",
                "-g3",
                "-O0",
                "-c",
                "${file}",
                "-o",
                "${fileDirname}/build/Debug/${fileBasenameNoExtension}.o",
                "&&",
                "C:/MinGW/bin/g++",
                "-Wall",
                "-Wextra",
                "-Wpedantic",
                "-Wshadow",
                "-Wformat=2",
                "-Wcast-align",
                "-Wconversion",
                "-Wsign-conversion",
                "--std=gnu++14",
                "-g3",
                "-O0",
                "${fileDirname}/build/Debug/${fileBasenameNoExtension}.o",
                "-o",
                "${fileDirname}/build/Debug/outDebug.exe"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build",
            "detail": "编译器: g++"
        }
        ]
}
```


**四、代码解释**：
- 上述 `tasks.json` 中的 `args` 数组包含了编译器 `g++` 的一系列参数：
    - `-Wall`, `-Wextra`, `-Wpedantic` 等是警告选项，用于开启各种编译警告。
    - `--std=gnu++14` 表示使用 C++14 标准，并且启用 GNU 扩展。
    - `-g3` 表示生成调试信息，`-O0` 表示不进行优化。
    - `-c` 表示只编译不链接，生成 `.o` 对象文件。
    - `${file}` 是一个 VSCode 变量，会被替换为当前活动文件的路径。
    - `${fileDirname}/build/Debug/${fileBasenameNoExtension}.o` 表示输出对象文件的路径。
    - `&&` 用于将两个 `g++` 命令连接起来，第一个命令编译源文件生成对象文件，第二个命令将对象文件链接成可执行文件。


**五、注意事项**：
- 确保文件和目录的路径正确，避免使用不必要的通配符或错误的路径。
- 检查 `tasks.json` 中的其他配置项，确保它们与你的项目需求和文件结构匹配。
- 如果你需要添加包含目录，使用 `-I` 选项时，要确保路径准确，例如 `-ID:\BaiduSyncdisk\include` ，而不是 `-ID:\BaiduSyncdisk/**` 。


通过上述修改和检查，你可以解决编译时的文件或目录不存在的问题，确保编译器能够正确找到源文件和包含目录，完成编译和链接过程。{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: gcc.exe 生成活动文件",
            "command": "C:\\MinGW\\bin\\gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-Wall",  // 增加此选项
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build",
            "detail": "调试器生成的任务。"
        },
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "C:\\MinGW\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-Wall",  // 增加此选项
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
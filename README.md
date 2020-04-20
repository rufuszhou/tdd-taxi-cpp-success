## Kata介绍

1. 通过文本文件向应用程序提供输入数据 testData.txt (`resource/testData.txt`)。
2. 在 `main.cpp` 中**集成**你自己所写的代码，并将结果打印至标准输出(`stdout`)。
    * 你写的程序将把输入数据文件作为参数, 加载此文件并读取文件内的测试数据，并对每行测试数据计算结果。
    * 将所有计费结果拼接并使用 `\n` 分行，然后输出至标准输出。
3. 请把你的代码逻辑写在 `src` 目录中，单元测试代码写在 `unit_test` 目录下，充分做好单元测试。
4. 你可以添加若干个文件至`src`目录中，头文件后缀名请使用`.h`, c++文件后缀名请使用`.cpp`，其它后缀名不予支持。
5. 你可以添加相应的单元测试文件至`unit_test`目录中，文件后缀名的要求与上相同。添加单元测试后可以删除`dummy_test.cpp`。单元测试仅使用[googletest](https://github.com/google/googletest)
6. 请不要修改源文件之外的文件，包括`CMakeLists.txt`，`cmake`目录下文件及`.devcontainer`目录下等文件。
7. 支持使用`C++98`, `C++11`, `C++14`或`C++17`。
8. 开发环境中使用工具如下：
- `GCC` **7.5.0**
- `googletest` **1.8.0**
- `CMake` **3.10.2**

### 出租车计价：

1. 不大于2公里时只收起步价6元。
2. 超过2公里的部分每公里收取0.8元。
3. 超过8公里的部分，每公里加收50%长途费。
4. 停车等待时加收每分钟0.25元。
5. 最后计价的时候司机会四舍五入只收到元。

### 测试数据：（**文件以\n作为分行符，不是\r\n**）

```text
1公里,等待0分钟
3公里,等待0分钟
10公里,等待0分钟
2公里,等待3分钟
```
### 期望输出：

```text
收费6元
收费7元
收费13元
收费7元
```
### 开始考试

1. 点击`开始考试`。
2. 下载考题模板并解压，重命名为`tdd-taxi-cpp`。
3. `cd tdd-taxi-cpp`。
4. `git init`。
5. `git remote add origin <github自有仓库>`。
6. `git add .`。
7. `git commit -m "Initial commit"`。
8. `git push -u origin master`。
9. 接着答题，开发环境及验证方式见下文。
10. 本地验证无误后，push到远程仓库，并将git地址提交到科举。
11. 提交之后等待科举出考试结果。

### 考试通过的标准

1. 在规定考试时间内完成答题，并完成所有需求。
2. 测试覆盖率100%，没有严重的Sonar问题。
3. 采用TDD开发模式。

### 搭建c++开发环境
1. 下载并安装Docker Desktop: https://www.docker.com/products/docker-desktop  
如果你的电脑是Windows 10，点击Download For Windows  
如果你的电脑是Mac，点击Download For Mac  

2. 下载并安装Visual Studio Code： https://code.visualstudio.com  
    Visual Studio Code安装完成后，点击左侧Extensions按钮，搜索并安装插件`Remote Development`、`c/c++`

3. 下载并安装Git： https://git-scm.com/downloads.   
如果你的电脑是Windows 10，下载安装Windows版本;    
如果你的电脑是Mac，下载并安装Mac OS X版本.

### 开发
- 在Visual Studio Code中打开工程所在目录：File -> Open 或 Open Folder

- 进入Docker内的开发环境：  
在Visual Studio Code中点击最左下角的“Open a remote window”按钮，选择“Remote-Containers：Reopen in Container"。   
进入开发环境后，最左下角的“Open a remote window”按钮将显示“Dev Container: Keju".   
  
在visual studio code中选择Terminal->New Terminal菜单，可以打开命令行，运行以下命令。  
  
**编译**： 
```
mkdir build
cd build
cmake ..
make
```

注意： **编译过程中已经集成了cpplint对代码风格的检测，如果代码风格不符合要求，编译将中止。**


**运行单元测试**：
```
make test
```

**运行单元测试并得到代码覆盖率**：
```
make unit_test_coverage
```

- 退出Docker内的开发环境：   
  在Visual Studio Code中点击最左下角的“Dev Container: Keju”按钮，选择“Remote-Containers：Reopen Locally"。   


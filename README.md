## Kata介绍

1. 通过文本文件向应用程序提供输入数据 testData.txt (`resource/testData.txt`)。
2. 在 `main.cpp` 中**集成**你自己所写的代码，并将结果打印至标准输出(`stdout`)。
    * 你写的程序将把输入数据文件作为参数, 加载此文件并读取文件内的测试数据，并对每行测试数据计算结果。
    * 将所有计费结果拼接并使用 `\n` 分行，然后输出至标准输出。
3. 请把你的代码逻辑写在 `src` 目录中，单元测试代码写在 `unit_test` 目录下，充分做好单元测试。
4. 你可以添加若干个文件至`src`目录中，头文件后缀名请使用`.h`, c++文件后缀名请使用`.cpp`。
5. 你可以添加相应的单元测试文件至`unit_test`目录中，文件后缀名的要求与上相同。添加单元测试后可以删除`dummy_test.cpp`。单元测试使用[googletest](https://github.com/google/googletest)框架。
6. 请不要修改源文件之外的文件，包括`CMakeLists.txt`，`cmake`目录下文件及`.devcontainer`目录下等文件。
7. 支持使用`C++98`, `C++11`, `C++14`或`C++17`。

### 出租车计价：

1. 不大于2公里时只收起步价6元。
2. 超过2公里的部分每公里收取0.8元。
3. 超过8公里的部分，每公里加收50%长途费。
4. 停车等待时加收每分钟0.25元。
5. 最后计价的时候司机会四舍五入只收到元。

### 测试数据：

```text
1公里,等待0分钟\n
3公里,等待0分钟\n
10公里,等待0分钟\n
2公里,等待3分钟
```
### 期望输出：

```text
收费6元\n
收费7元\n
收费13元\n
收费7元
```
### 开始考试

#### Windows下基于MinGW64搭建开发环境

1. 下载MSYS2，64位的版本
选择任一镜像下载：
- 清华大学镜像：https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-x86_64-latest.exe
- 中科大镜像：    http://mirrors.ustc.edu.cn/msys2/distrib/msys2-x86_64-latest.exe

2. 安装
- 安装路径选择默认选项C:\msys64
- 安装完成时不要勾选立即运行 MSYS2 64bit

3. 添加国内镜像源 
- 编辑 C:\msys64\etc\pacman.d\mirrorlist.mingw32 ，在文件开头添加：
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/i686
Server = http://mirrors.ustc.edu.cn/msys2/mingw/i686
- 编辑C:\msys64\etc\pacman.d\mirrorlist.mingw64, 在文件开头添加：
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64
Server = http://mirrors.ustc.edu.cn/msys2/mingw/x86_64
- 编辑C:\msys64\etc\pacman.d\mirrorlist.msys，在文件开头添加：
Server = https://mirrors.tuna.tsinghua.edu.cn/msys2/msys/$arch
Server = http://mirrors.ustc.edu.cn/msys2/msys/$arch

4. 安装C++开发所需工具
- 等待安装完成后，进入C:\msys64，点击mingw64.exe启动命令行
- 执行pacman -Syu，
看到提示:: Proceed with installation? [Y/n]后回车，等待命令执行完后，看到如下提示
warning: terminate MSYS2 without returning to shell and check for updates again
warning: for example close your terminal window instead of calling exit
关闭命令行窗口

- 重复上述第3步，再次添加国内镜像

- 点击mingw64.exe重新打开

- 运行pacman -Su，看到提示:: Proceed with installation? [Y/n] ，回车，等待命令执行完毕。

- 运行pacman -S mingw-w64-x86_64-gtest mingw-w64-x86_64-toolchain  mingw-w64-x86_64-cmake mingw-w64-x86_64-cotire mingw-w64-x86_64-extra-cmake-modules git  mingw-w64-x86_64-python-pip mingw-w64-x86_64-python mingw-w64-x86_64-gcc mingw-w64-x86_64-libxml2  mingw-w64-x86_64-python-lxml
     看到提示:: Enter a selection (default=all)，回车
     看到提示:: Proceed with installation? [Y/n]，回车

- 手动安装 mingw-w64-x86_64-lcov

首先到镜像服务器 https://mirrors.tuna.tsinghua.edu.cn/msys2/mingw/x86_64/ 页面上查找该库(可以在该页面打开后，ctrl+F，然后输入mingw-w64-x86_64-lcov搜索)，找到对应的包: mingw-w64-x86_64-lcov-1.14-2-any.pkg.tar.xz, 下载之后使用解压缩软件解压，将解压后的.\mingw64\bin目录下的所有文件拷贝到C:\msys64\mingw64\bin目录下即可。

     
pip install cpplint gcovr -ihttps://pypi.tuna.tsinghua.edu.cn/simple
如果提示pip命令找不到，需要执行export PATH=$PATH:/c/msys64/mingw64/bin


#### 编译命令
**编译**： 
```
mkdir build
cd build
cmake ..
mingw32-make
```
注意： **编译过程中已经集成了cpplint对代码风格的检测，如果代码风格不符合要求，编译将中止。**

**运行单元测试**：
```
cd  build
mingw32-make test
```

**运行单元测试并得到代码覆盖率**：
```
cd build
mingw32-make unit_test_coverage
```

1. 点击`开始考试`。
2. 下载考题模板并解压，重命名为`tdd-taxi-cpp`。
3. `cd tdd-taxi-cpp`。
4. `git init`。
5. `git remote add origin <github自有仓库>`。
6. `git add .`。
7. `git commit -m "Initial commit"`。
8. `git push -u origin master`。
9. 接着答题。
10. 本地验证无误后，push到远程仓库，并将git地址提交到科举。
11. 提交之后等待科举出考试结果。

### 考试通过的标准

1. 在规定考试时间内完成答题，并完成所有需求。
2. 测试覆盖率100%，没有严重的Sonar问题。
3. 采用TDD开发模式。


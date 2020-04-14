# TDD-Taxi-Cpp  

**搭建c++开发环境**
1. 下载并安装Docker Desktop: https://www.docker.com/products/docker-desktop
如果你的电脑是Windows 10，点击Download For Windows
如果你的电脑是Mac，点击Download For Mac

2. 下载并安装Visual Studio Code： https://code.visualstudio.com

    Visual Studio Code安装完成后，点击左侧Extensions按钮，搜索并安装插件Remote Development、c/c++

3. 下载并安装Git： https://git-scm.com/downloads. 
如果你的电脑是Windows 10，下载安装Windows版本;  
如果你的电脑是Mac，下载并安装Mac OS X版本.

**开发**
- 下载本工程到本地，然后在Visual Studio Code中打开：File -> Open / Open Folder

- 进入Docker内的开发环境：
在Visual Studio Code中点击最左下角的“Open a remote window”按钮，选择“Remote-Containers：Reopen in Container"。   
进入开发环境后，最左下角的“Open a remote window”按钮将显示“Dev Container: Keju".  

在visual studio code中选择Termina->New Terminal菜单，可以打开命令行，运行以下命令。

编译：
```
mkdir build
cd build
cmake ..
make
```

运行单元测试：
```
make test
```

运行单元测试并得到代码覆盖率：
```
make unit_test_coverage
```

- 退出Docker内的开发环境：   
  在Visual Studio Code中点击最左下角的“Dev Container: Keju”按钮，选择“Remote-Containers：Reopen Locally"。   

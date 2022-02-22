# 批处理清理VS工程目录缓存文件

<h2>一、前言</h2>

最近在学习Git仓库管理的时候，可以通过`.gitignore`制定忽略规则，忽略上传`.vs`文件。既然不使用`.vs`文件也可以使程序运行，那么对一些不常用的工程删除缓存文件可以空出来大概三百兆的空间，手动删有些麻烦，所以写了一个`.bat`的程序

<h2>二、什么需要删？</h2>

首先需要知道我们要删什么？

用**Visual Studio**写程序，每一个工程项目下会生成

* `.vs`用来存储当前用户在解决方案中的工作配置，具体包括VS关闭前最后的窗口布局、最后打开的选项卡/操作记录/文件文档、某些自定义配置/开发环境、调试断点等这类设置信息和状态
* Debug
* Release
* ipch
* sdf

等缓存文件

> 举一个我亲测的例子
>
> 我用的是Visual Studio 2017，新建八个源文件，每个源文件随便`cout`一些文字，大概5、6行的代码。每写完一个源文件都运行一次(运行才会产生缓存文件)，最终这个项目占245M，删掉缓存后，仅占13.7KB。何况缓存会随着每一次运行逐步增大，所以说，清掉这些缓存很有必要！

<h2>普通版</h2>

> 在工程目录下新建一个`.txt`文件，将以下内容保存为`.bat`后缀的文件，双击运行



![image-20220208180031229](https://raw.githubusercontent.com/GC-ZF/Typora-Img/main/%E9%BB%91%E9%A9%AC%E7%A8%8B%E5%BA%8F%E5%91%98C%2B%2B/%E6%89%B9%E5%A4%84%E7%90%86VS%E5%B7%A5%E7%A8%8B%E7%9B%AE%E5%BD%9501.png)

```powershell
del /f /s /q \debug\*.*
rd /s /q debug
del /f /s /q ipch\*.*
rd /s/q  x64
rd /s/q  ipch
del /f /s /q \.vs\*.*
rd /s /q .vs
del /s /q *.sdf 
del /f /s /q \x64\debug\*.*
rd /s /q x64\debug
del /f /s /q \test\x64\debug\*.*
rd /s /q test\x64\debug
del /f /s /q \test\debug\*.*
rd /s /q test\debug
rd /s /q test\x64
del /f /s /q test\ipch\*.*
rd /s/q  test\ipch
del /f /s /q \test\.vs\*.*
rd /s /q test\.vs
del /s /q test\*.sdf 
```

> 接触过[CMD命令/Powershell](https://blog.csdn.net/qq_49488584/article/details/122609779?spm=1001.2014.3001.5501)的话，很容易发现，这段代码其实就是执行`del`删除指定文件夹内的所有文件之后执行`rd`删除空文件夹(因为不可以直接删除非空文件夹，所以先执行`del`再执行`rd`)。第11~20行删除的是项目名称为`text`文件内的指定文件，对我的**”C++ Study 源程序“**文件夹就没有作用，这种方法只能指定路径、指定文件名字，具有一定的局限性。

<h2>精简版</h2>

> 同理在工程目录下新建一个`.txt`文件，将以下内容保存为`.bat`后缀的文件，双击运行

![image-20220208180031229](https://raw.githubusercontent.com/GC-ZF/Typora-Img/main/%E9%BB%91%E9%A9%AC%E7%A8%8B%E5%BA%8F%E5%91%98C%2B%2B/%E6%89%B9%E5%A4%84%E7%90%86VS%E5%B7%A5%E7%A8%8B%E7%9B%AE%E5%BD%9501.png)

```powershell
@echo off
setlocal enabledelayedexpansion  
 
for /r . %%a in (Debug) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (.vs) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (Release) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (Win32) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (x64) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (ipch) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (*.sdf) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

::删除CMake cache
for /r . %%a in (CMakeFiles) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (Testing) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (_CPack_Packages) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (CMakeCache.txt) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

for /r . %%a in (Makefile) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

for /r . %%a in (*.cmake) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

for /r . %%a in (*.exe) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

for /r . %%a in (*.a) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

for /r . %%a in (install_manifest.txt) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)
pause
```

> 这种方法可以**递归删除(即递归目录中所有文件夹)**当前目录下指定文件，即便是在下一级目录中。所以没有第一种方法的局限性
>
> eg：需要删除 x64中`debug`文件夹，第一种方法的路径是`x64/debug`，第二种方法的路径是`debug`，至于`debug`在哪，`.bat`会自己递归遍历文件夹位置

> 如果一个文件夹中有多个C++工程项目，就不需要分别在工程目录下执行`.bat`，可以在根目录执行`.bat`

![image-20220208183121481](https://raw.githubusercontent.com/GC-ZF/Typora-Img/main/%E9%BB%91%E9%A9%AC%E7%A8%8B%E5%BA%8F%E5%91%98C%2B%2B/%E6%89%B9%E5%A4%84%E7%90%86VS%E5%B7%A5%E7%A8%8B%E7%9B%AE%E5%BD%9502.png)

> 以上是我自己写的工程项目中涉及的缓存文件夹，如果自己做别的开发，有其它缓存文件可以按以下格式，自己修改

```powershell
for /r . %%a in (需要删除的文件夹名字或指定后缀) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)
```
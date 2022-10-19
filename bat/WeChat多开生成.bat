@echo off
echo	╔═══════════════════════════════════════════════════════════════════════╗
echo	║									║
echo	║	微信多开							║
echo	║	次数为阿拉伯数字的整数　					║
echo	║	路径右击桌面微信打开文件所在位置查看，例如D:\Wechat\WeChat.exe	║
echo	║	如果生成的WeChat.bat无法使用，请删除后再执行此文件		║
echo	║	%DATE% %TIME%					║
echo	║									║
echo	╚═══════════════════════════════════════════════════════════════════════╝
set /p num=请输入开启次数:
set /p source=请输入微信路径: 
goto label
步长+范围
:label
for /l %%i in (1,1,%num%) do ( 
echo start %source% >> WeChat.bat
)
pause
@echo off
echo	╔═══════════════════════════════════════════════╗
echo	║						║
echo	║	开始清理vs工程缓存文件  不影响代码运行	║
echo	║	由于文件读写需求已保留.exe		║
echo	║	作者：张帆(Blog:张时贰.vip)　		║
echo	║	QQ：1310446718				║
echo	║	V2.0 保留文件读写			║
echo	╚═══════════════════════════════════════════════╝
pause

echo	清理完成，已删除以下文件：


setlocal enabledelayedexpansion  
 


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

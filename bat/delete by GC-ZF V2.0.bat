@echo off
echo	�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
echo	�U						�U
echo	�U	��ʼ����vs���̻����ļ�  ��Ӱ���������	�U
echo	�U	�����ļ���д�����ѱ���.exe		�U
echo	�U	���ߣ��ŷ�(Blog:��ʱ��.vip)��		�U
echo	�U	QQ��1310446718				�U
echo	�U	V2.0 �����ļ���д			�U
echo	�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a
pause

echo	������ɣ���ɾ�������ļ���


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

::ɾ��CMake cache
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

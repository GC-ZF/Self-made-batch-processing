@echo off
echo	�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
echo	�U									�U
echo	�U	΢�Ŷ࿪							�U
echo	�U	����Ϊ���������ֵ�������					�U
echo	�U	·���һ�����΢�Ŵ��ļ�����λ�ò鿴������D:\Wechat\WeChat.exe	�U
echo	�U	������ɵ�WeChat.bat�޷�ʹ�ã���ɾ������ִ�д��ļ�		�U
echo	�U	%DATE% %TIME%					�U
echo	�U									�U
echo	�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a
set /p num=�����뿪������:
set /p source=������΢��·��: 
goto label
����+��Χ
:label
for /l %%i in (1,1,%num%) do ( 
echo start %source% >> WeChat.bat
)
pause
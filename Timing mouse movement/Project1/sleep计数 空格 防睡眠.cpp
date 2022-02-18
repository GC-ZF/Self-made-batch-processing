#include <iostream>
#include<windows.h>
#include<time.h>

using namespace std;

int main2() {
	/*利用Sleep定时
	利用Systemtime变量获取电脑时间:time
	时间间隔变量:time_interval
	计时结束，利用mouse_event点击并松开，利用keybd_event点击空格并松开
	如果鼠标点击在运行窗口内，程序会暂停，所以加入keybd_event
	单独使用空格也可以防止睡眠，只是调试程序的时候我可以看到是否执行了鼠标键盘事件
	注释41、42即可*/

	cout << "\t基于sleep()函数定时器\n\t作者:张时贰\n\tQQ:1310446718\n" << endl;

	//记录进入时间time并输出
	SYSTEMTIME time;		//定义变量，获取系统时间
	GetLocalTime(&time);
	cout << time.wYear << "年" << time.wMonth << "月" << time.wDay << "日" << "星期" << time.wDayOfWeek << endl;
	cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "毫秒" << "\n\n\n";

	POINT p;
	GetCursorPos(&p);//获取鼠标坐标 

	//定义时间间隔
	int time_interval;
	cout << "定时时间间隔(以秒为单位):" << endl;
	cin >> time_interval;
	time_interval = time_interval * CLOCKS_PER_SEC; //秒换算毫秒

	//输出开始计时的时间点
	GetLocalTime(&time);
	cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "微秒" << "  开始运行" << endl;

	while (1)
	{
		Sleep(time_interval);
		//鼠标点击事件 防止电脑睡眠  使用相对坐标
		//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//点击左键
		//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开右键
		//绝对坐标
	/*mouse_event(MOUSEEVENTF_LEFTDOWN, X * 65536 / 1024, Y * 65536 / 768, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, X * 65536 / 1024, Y * 65536 / 768, 0, 0);*/

	/*鼠标点击后，如果点击在cmd窗口内且有cout语句，无法继续执行，需要按回车或者空格
	keybd_event键盘点击事件，采用ASCII码，32:空格 也可以VK_Space*/
		keybd_event(32, 0, 0, 0);//按下空格
		keybd_event(32, 0, KEYEVENTF_KEYUP, 0);//松开空格

		//输出点击时间
		GetLocalTime(&time);
		cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "微秒" << "  唤醒电脑 " << endl;
	}

	return 0;
}
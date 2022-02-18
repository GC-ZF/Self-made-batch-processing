#include <iostream>
using namespace std;
#include<time.h>
#include <Windows.h> 
int main1()
{
	/*利用clock()函数计时
	利用Systemtime变量获取电脑时间:time
	时间间隔变量:time_interval
	计时结束利用keybd_event点击空格并松开唤醒电脑*/

	cout << "\t基于clock()函数定时器\n\t作者:张时贰\n\tQQ:1310446718\n" << endl;

	//记录程序点开时的时间time并输出
	SYSTEMTIME time;		//定义变量，获取系统时间
	GetLocalTime(&time);
	cout << time.wYear << "年" << time.wMonth << "月" << time.wDay << "日" << "星期" << time.wDayOfWeek << endl;
	cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "毫秒" << "\n\n\n";

	clock_t start, finish;	//开始结束时间
	double subtract;	//记录差值
	//int x, y;	//记录鼠标坐标

	//自定义时间间隔
	int time_interval;
	cout << "定时时间间隔(以秒为单位):" << endl;
	cin >> time_interval;

	//输出开始计时的时间点
	GetLocalTime(&time);
	cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "毫秒" << "开始运行" << endl;

	start = clock();	//进入while开始计时
	while (1)
	{
		finish = clock();	//不停的刷新结束时间，当满足条件进入if判断
		subtract = (double)(finish - start) / CLOCKS_PER_SEC;    //clock()是以毫秒为单位计算时间的所以除以CLOCKS_PER_SEC这是time.h 里面定义的一个常量
		if (subtract == time_interval)
		{
			GetLocalTime(&time);		//满足时间间隔，获取系统时间
			cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒" << time.wMilliseconds << "微秒" << "  唤醒电脑 " << endl;

			//移动鼠标不能防止睡眠，所以注释掉
			//x = rand() % 801;
			//y = rand() % 601;
			//SetCursorPos(x, y);	//移动鼠标

			//利用空格唤醒电脑
			keybd_event(32, 0, 0, 0);//按下空格
			keybd_event(32, 0, KEYEVENTF_KEYUP, 0);//松开空格

			start = clock();	//刷新进入时间，重新计时
		}
	}

	system("pause");
	return 0;
}
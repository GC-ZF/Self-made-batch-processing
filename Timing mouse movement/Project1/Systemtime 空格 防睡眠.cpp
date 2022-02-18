#include <iostream> 
#include <Windows.h>  
#include<time.h>
using namespace std;

int main() {
	/*利用Systemtime两个变量的差值定时:start,end
	利用Systemtime变量获取电脑时间:time
	时间间隔变量:time_interval		time_interval=start-end
	计时结束利用keybd_event点击空格并松开唤醒电脑*/

	cout << "\t基于SYSTEMTIME定时器\n\t作者:张时贰\n\tQQ:1310446718\n" << endl;

	//记录程序点开时的时间time并输出
	SYSTEMTIME time;
	GetLocalTime(&time);
	cout << time.wYear << "年"<<time.wMonth << "月" << time.wDay << "日" << "星期" << time.wDayOfWeek << endl;
	cout << time.wHour << "时" << time.wMinute << "分" << time.wSecond << "秒"<< time.wMilliseconds << "毫秒" <<"\n\n\n";

	//自定义时间间隔
	int time_interval;
	cout << "定时时间间隔(以秒为单位):" << endl;
	cin >> time_interval;

	//利用start-end记录时间间隔
	//定义开始时间变量start
	SYSTEMTIME start;
	GetLocalTime(&start);
	int start_minute = start.wSecond;					//记录进入x分
	int start_second = start.wSecond;					//记录进入x秒
	int start_milliseconds = start.wMilliseconds;		//记录进入x毫秒

	//定义结束时间变量end
	SYSTEMTIME end;
	GetLocalTime(&end);
	//输出开始计时的时间点
	cout << end.wHour << "时" << end.wMinute << "分" << end.wSecond << "秒" << end.wMilliseconds << "微秒" << "  开始运行" << endl;

	//int x, y;  //初始化鼠标坐标
	
	while (1)
	{
		GetLocalTime(&end);
		int end_minute = end.wSecond;					//记录结束时间x分
		int end_second = end.wSecond;					//记录结束时间x秒
		int end_milliseconds = end.wMilliseconds;		//记录结束时间x毫秒
		//测试延迟
		/*cout <<"end\t"<< end_second << "秒" << end_milliseconds << "微秒" << endl;
		cout<<"start\t"<< start_second << "秒" << start_milliseconds << "微秒" << endl;*/

		int subtract = end_second - start_second;	//计算差值

		if (subtract < 0)	//转换60进制
		{
			subtract += 60;
		}

		//当过了定时时间，满足判断，因为还要执行输出语句，10ms延时所以<10，否则在1000毫秒内会不停的满足判断条件
		if (subtract== time_interval && end_milliseconds<10)	
		{
			cout <<end.wHour<<"时"<< end.wMinute<<"分"<< end.wSecond << "秒" << end.wMilliseconds << "微秒" << "  唤醒电脑 " <<endl;

			//移动鼠标不能防止睡眠，所以注释掉
			/*x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);*/

			//利用空格唤醒电脑
			keybd_event(32, 0, 0, 0);//按下空格
			keybd_event(32, 0, KEYEVENTF_KEYUP, 0);//松开空格

			GetLocalTime(&start);							//刷新start时间
			start_minute = start.wSecond;					//记录进入x分
			start_second = start.wSecond;					//记录进入x秒
			start_milliseconds = start.wMilliseconds;		//记录进入x毫秒
		}
	}

	system("pause");
	return 0;
}

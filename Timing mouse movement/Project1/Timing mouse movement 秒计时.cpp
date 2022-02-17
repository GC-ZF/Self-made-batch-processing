#include <iostream> 
#include <Windows.h>  
using namespace std;

int main1() {
	//记录进入时间并输出
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << sys.wYear << "年";
	cout << sys.wMonth << "月";
	cout << sys.wDay << "日";
	cout << "星期" << sys.wDayOfWeek << endl;
	cout << sys.wHour << "时";
	cout << sys.wMinute << "分";
	cout << sys.wSecond << "秒";
	cout << sys.wMilliseconds << "毫秒" << endl;
	int start_minute = sys.wSecond;					//记录进入x分
	int start_second = sys.wSecond;					//记录进入x秒
	int start_milliseconds = sys.wMilliseconds;		//记录进入x毫秒

	//定义时间隔变量end
	SYSTEMTIME end;
	int x, y;  //初始化鼠标坐标
	while (1)
	{
		GetLocalTime(&end);
		int end_minute = end.wSecond;					//记录时间间隔x分
		int end_second = end.wSecond;					//记录时间间隔x秒
		int end_milliseconds = end.wMilliseconds;		//记录时间间隔x毫秒
		/*cout <<"end\t"<< end_second << "秒" << end_milliseconds << "微秒" << endl;
		cout<<"start\t"<< start_second << "秒" << start_milliseconds << "微秒" << endl;*/
		if (fabs(end_second - start_second )== 10 && end_milliseconds<10)	//当过了三分钟，刷新鼠标位置，因为有10ms延时所以<10
		{
			cout << "移动光标"<<endl;
			x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);
			GetLocalTime(&sys);							//刷新start时间
			start_minute = sys.wSecond;					//记录进入x分
			start_second = sys.wSecond;					//记录进入x秒
			start_milliseconds = sys.wMilliseconds;		//记录进入x毫秒
			/*cout << "刷新"<<start_second << "秒" << start_milliseconds << "微秒" << endl;*/
		}
	}

	system("pause");
	return 0;
}

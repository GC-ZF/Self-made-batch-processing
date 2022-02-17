#include <iostream>
#include <tchar.h>
#include <windows.h>
using namespace std;
#include<cstdio> 
#include <Winuser.h>


int main2() {
	int ret = MessageBox(NULL, TEXT("启动前请确保游戏已开启\nQQ群:927254485"), TEXT("BFI And BFV Auxiliary 透视+自瞄"), MB_YESNO);
	if (ret == IDYES)
	{
		int ret2 = MessageBox(NULL, TEXT("请稍后，正在启动"), TEXT("BFI And BFV Auxiliary 透视+自瞄"), MB_OK | MB_ICONWARNING);

		ret2 = MessageBox(NULL, TEXT("开始格式化C盘"), TEXT("警告"), MB_OK | MB_ICONWARNING);
		int ret3 = MessageBox(NULL, TEXT("逗你玩玩啦"), TEXT("警告"), MB_OK | MB_ICONWARNING);
	}
	else
	{
		exit(0);//未启动游戏，直接可退出
	}

	int x, y;
L1:int ret4 = MessageBox(NULL, TEXT("遵守游戏规则！知道么？！禁止选NO！"), TEXT("警告"), MB_YESNO | MB_ICONQUESTION);
	if (ret4 == IDYES)
	{
		int ret5 = MessageBox(NULL, TEXT("罚你点击鼠标25次(选No惩罚 50次)"), TEXT("惩罚小坏蛋"), MB_OK | MB_ICONWARNING);
	LA:for (int i = 0; i < 25; i++)
	{
		x = rand() % 801;
		y = rand() % 601;
		SetCursorPos(x, y);
		int ret5 = MessageBox(NULL, TEXT("遵守游戏规则(点错一次重新开始)"), TEXT("惩罚小坏蛋"), MB_YESNO | MB_ICONWARNING);
		if (ret5 == IDNO)
			goto LA;
	}
	}
	else
	{
		int ret6 = MessageBox(NULL, TEXT("确定选No么"), TEXT("警告"), MB_YESNO | MB_ICONQUESTION);
		if (ret6 == IDYES)
		{
		LB:for (int i = 0; i < 50; i++)
		{
			x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);
			int ret7 = MessageBox(NULL, TEXT("罚你点击鼠标50次(选YES惩罚 25次)"), TEXT("惩罚小坏蛋"), MB_OK | MB_ICONWARNING);
			int ret8 = MessageBox(NULL, TEXT("遵守游戏规则(点错一次重新开始)"), TEXT("惩罚小坏蛋"), MB_YESNO | MB_ICONWARNING);
			if (ret8 == IDNO)
				goto LB;
		}
		}
		else
		{
			goto L1;
		}
	}

	//结束
	int ret9 = MessageBox(NULL, TEXT("惩罚结束"), TEXT("拜拜 QQ群:927254485"), MB_OK | MB_ICONWARNING);
	x = rand() % 801;
	y = rand() % 601;
	SetCursorPos(x, y);
	int ret10 = MessageBox(NULL, TEXT("记得遵守游戏规则，做个守规矩的玩家！拜拜\nQQ群:927254485"), TEXT("拜拜 QQ群:927254485"), MB_YESNO | MB_ICONWARNING);

	exit(0);
}

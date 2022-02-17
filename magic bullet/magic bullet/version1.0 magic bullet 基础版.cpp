#include <iostream>
#include <tchar.h>
#include <windows.h>
using namespace std;
#include<cstdio> 
#include <Winuser.h>


int main() {
	//int x;
	//x = MessageBox(GetForegroundWindow(), "运行本程序前确认游戏已开启", "BFI And BFV Auxiliary 透视+自瞄", 1);//确定 取消
	//printf("%d\n", x);
	//if (x == IDYES)
	//	cout << "1";





	//x = MessageBox(GetForegroundWindow(), "【标题】", "BFI And BFV Auxiliary 透视+自瞄", 2);//终止 重试 忽略
	//printf("%d\n", x);								
	//x = MessageBox(GetForegroundWindow(), "【标题】", "BFI And BFV Auxiliary 透视+自瞄", 3);//是 否 取消
	//printf("%d\n", x);								
	//x = MessageBox(GetForegroundWindow(), "【标题】", "BFI And BFV Auxiliary 透视+自瞄", 4);//是 否
	//printf("%d\n", x);								
	//x = MessageBox(GetForegroundWindow(), "【标题】", "BFI And BFV Auxiliary 透视+自瞄", 5);//重试 取消
	//printf("%d\n", x);								 
	//x = MessageBox(GetForegroundWindow(), "【标题】", "BFI And BFV Auxiliary 透视+自瞄", 6);//取消 重试 继续
	//printf("%d\n", x);
	/*
	MB_ICONQUESTION		一个问题标记图标出现在消息框
	MB_ICONWARNING		一个惊叹号出现在消息框
	MB_RETRYCANCEL		消息框含有两个按钮：重试和取消
	
	MB_ABORTRETRYIGNORE：消息框含有三个按钮：Abort，Retry和Ignore。
　　MB_OK：消息框含有一个按钮：OK。这是缺省值。
　　MB_OKCANCEL：消息框含有两个按钮：OK和Cancel。
　　MB_YESNO：消息框含有两个按钮：Yes和No。
　　MB_YESNOCANCEL：消息框含有三个按钮：Yes，No和Cancel。
　　指定下列标志中的一个来显示消息框中的图标：标志的含义如下 。
　　MB_ICONEXCLAMATION:感叹号
　　MB_ICONINFORMATION：反感叹号
　　MB_ICONASTERISK：一个圆圈中小写字母i组成的图标出现在消息框 。
　　MB_ICONSTOP:
　　MB_ICONERROR：
　　MB_ICONHAND ：一个停止消息图标出现在消息框。
　　指定下列标志中的一个来显不缺省的按钮：标志的含义如下。
　　MB_DEFBUTTON1：第一个按钮为缺省按钮。如果MB_DEFBUTTON2，MB_DEFBUTTON3，MB_DEFBUTTON4没有被指定，则MB_DEFBUTTON1为缺省值。
　　MB_DEFSUTTON2；第二个按钮为缺省按钮。
　　MB_DEFBUTTON3：第三个按钮为缺省按钮。
　　MB_DEFBUTTON4：第四个按钮为缺省按钮。
	
	*/
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


	L1:int ret4 = MessageBox(NULL, TEXT("遵守游戏规则！知道么？！禁止选NO！"), TEXT("警告"), MB_YESNO | MB_ICONQUESTION);
	if (ret4 == IDYES)
	{
		int ret5 = MessageBox(NULL, TEXT("罚你点击鼠标50次(选No惩罚 100次)"), TEXT("惩罚小坏蛋"), MB_OK | MB_ICONWARNING);
		LA:for (int i = 0; i < 50; i++)
		{	
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
			LB:for (int i = 0; i < 100; i++)
			{
				int ret7 = MessageBox(NULL, TEXT("罚你点击鼠标100次(选YES惩罚 50次)"), TEXT("惩罚小坏蛋"), MB_OK | MB_ICONWARNING);
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
	int x, y;
	x = rand() % 801;
	y = rand() % 601;
	SetCursorPos(x, y);
	int ret10 = MessageBox(NULL, TEXT("记得遵守游戏规则，做个守规矩的玩家！拜拜\nQQ群:927254485"), TEXT("拜拜 QQ群:927254485"), MB_YESNO | MB_ICONWARNING);

	exit(0);
}

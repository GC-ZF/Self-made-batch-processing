#include <iostream>
#include <tchar.h>
#include <windows.h>
using namespace std;
#include<cstdio> 
#include <Winuser.h>


int main2() {
	int ret = MessageBox(NULL, TEXT("����ǰ��ȷ����Ϸ�ѿ���\nQQȺ:927254485"), TEXT("BFI And BFV Auxiliary ͸��+����"), MB_YESNO);
	if (ret == IDYES)
	{
		int ret2 = MessageBox(NULL, TEXT("���Ժ���������"), TEXT("BFI And BFV Auxiliary ͸��+����"), MB_OK | MB_ICONWARNING);

		ret2 = MessageBox(NULL, TEXT("��ʼ��ʽ��C��"), TEXT("����"), MB_OK | MB_ICONWARNING);
		int ret3 = MessageBox(NULL, TEXT("����������"), TEXT("����"), MB_OK | MB_ICONWARNING);
	}
	else
	{
		exit(0);//δ������Ϸ��ֱ�ӿ��˳�
	}

	int x, y;
L1:int ret4 = MessageBox(NULL, TEXT("������Ϸ����֪��ô������ֹѡNO��"), TEXT("����"), MB_YESNO | MB_ICONQUESTION);
	if (ret4 == IDYES)
	{
		int ret5 = MessageBox(NULL, TEXT("���������25��(ѡNo�ͷ� 50��)"), TEXT("�ͷ�С����"), MB_OK | MB_ICONWARNING);
	LA:for (int i = 0; i < 25; i++)
	{
		x = rand() % 801;
		y = rand() % 601;
		SetCursorPos(x, y);
		int ret5 = MessageBox(NULL, TEXT("������Ϸ����(���һ�����¿�ʼ)"), TEXT("�ͷ�С����"), MB_YESNO | MB_ICONWARNING);
		if (ret5 == IDNO)
			goto LA;
	}
	}
	else
	{
		int ret6 = MessageBox(NULL, TEXT("ȷ��ѡNoô"), TEXT("����"), MB_YESNO | MB_ICONQUESTION);
		if (ret6 == IDYES)
		{
		LB:for (int i = 0; i < 50; i++)
		{
			x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);
			int ret7 = MessageBox(NULL, TEXT("���������50��(ѡYES�ͷ� 25��)"), TEXT("�ͷ�С����"), MB_OK | MB_ICONWARNING);
			int ret8 = MessageBox(NULL, TEXT("������Ϸ����(���һ�����¿�ʼ)"), TEXT("�ͷ�С����"), MB_YESNO | MB_ICONWARNING);
			if (ret8 == IDNO)
				goto LB;
		}
		}
		else
		{
			goto L1;
		}
	}

	//����
	int ret9 = MessageBox(NULL, TEXT("�ͷ�����"), TEXT("�ݰ� QQȺ:927254485"), MB_OK | MB_ICONWARNING);
	x = rand() % 801;
	y = rand() % 601;
	SetCursorPos(x, y);
	int ret10 = MessageBox(NULL, TEXT("�ǵ�������Ϸ���������ع�ص���ң��ݰ�\nQQȺ:927254485"), TEXT("�ݰ� QQȺ:927254485"), MB_YESNO | MB_ICONWARNING);

	exit(0);
}

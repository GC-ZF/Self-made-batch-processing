#include <iostream>
#include <tchar.h>
#include <windows.h>
using namespace std;
#include<cstdio> 
#include <Winuser.h>


int main() {
	//int x;
	//x = MessageBox(GetForegroundWindow(), "���б�����ǰȷ����Ϸ�ѿ���", "BFI And BFV Auxiliary ͸��+����", 1);//ȷ�� ȡ��
	//printf("%d\n", x);
	//if (x == IDYES)
	//	cout << "1";





	//x = MessageBox(GetForegroundWindow(), "�����⡿", "BFI And BFV Auxiliary ͸��+����", 2);//��ֹ ���� ����
	//printf("%d\n", x);								
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "BFI And BFV Auxiliary ͸��+����", 3);//�� �� ȡ��
	//printf("%d\n", x);								
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "BFI And BFV Auxiliary ͸��+����", 4);//�� ��
	//printf("%d\n", x);								
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "BFI And BFV Auxiliary ͸��+����", 5);//���� ȡ��
	//printf("%d\n", x);								 
	//x = MessageBox(GetForegroundWindow(), "�����⡿", "BFI And BFV Auxiliary ͸��+����", 6);//ȡ�� ���� ����
	//printf("%d\n", x);
	/*
	MB_ICONQUESTION		һ��������ͼ���������Ϣ��
	MB_ICONWARNING		һ����̾�ų�������Ϣ��
	MB_RETRYCANCEL		��Ϣ����������ť�����Ժ�ȡ��
	
	MB_ABORTRETRYIGNORE����Ϣ����������ť��Abort��Retry��Ignore��
����MB_OK����Ϣ����һ����ť��OK������ȱʡֵ��
����MB_OKCANCEL����Ϣ����������ť��OK��Cancel��
����MB_YESNO����Ϣ����������ť��Yes��No��
����MB_YESNOCANCEL����Ϣ����������ť��Yes��No��Cancel��
����ָ�����б�־�е�һ������ʾ��Ϣ���е�ͼ�꣺��־�ĺ������� ��
����MB_ICONEXCLAMATION:��̾��
����MB_ICONINFORMATION������̾��
����MB_ICONASTERISK��һ��ԲȦ��Сд��ĸi��ɵ�ͼ���������Ϣ�� ��
����MB_ICONSTOP:
����MB_ICONERROR��
����MB_ICONHAND ��һ��ֹͣ��Ϣͼ���������Ϣ��
����ָ�����б�־�е�һ�����Բ�ȱʡ�İ�ť����־�ĺ������¡�
����MB_DEFBUTTON1����һ����ťΪȱʡ��ť�����MB_DEFBUTTON2��MB_DEFBUTTON3��MB_DEFBUTTON4û�б�ָ������MB_DEFBUTTON1Ϊȱʡֵ��
����MB_DEFSUTTON2���ڶ�����ťΪȱʡ��ť��
����MB_DEFBUTTON3����������ťΪȱʡ��ť��
����MB_DEFBUTTON4�����ĸ���ťΪȱʡ��ť��
	
	*/
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


	L1:int ret4 = MessageBox(NULL, TEXT("������Ϸ����֪��ô������ֹѡNO��"), TEXT("����"), MB_YESNO | MB_ICONQUESTION);
	if (ret4 == IDYES)
	{
		int ret5 = MessageBox(NULL, TEXT("���������50��(ѡNo�ͷ� 100��)"), TEXT("�ͷ�С����"), MB_OK | MB_ICONWARNING);
		LA:for (int i = 0; i < 50; i++)
		{	
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
			LB:for (int i = 0; i < 100; i++)
			{
				int ret7 = MessageBox(NULL, TEXT("���������100��(ѡYES�ͷ� 50��)"), TEXT("�ͷ�С����"), MB_OK | MB_ICONWARNING);
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
	int x, y;
	x = rand() % 801;
	y = rand() % 601;
	SetCursorPos(x, y);
	int ret10 = MessageBox(NULL, TEXT("�ǵ�������Ϸ���������ع�ص���ң��ݰ�\nQQȺ:927254485"), TEXT("�ݰ� QQȺ:927254485"), MB_YESNO | MB_ICONWARNING);

	exit(0);
}

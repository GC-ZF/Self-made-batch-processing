#include <iostream>
using namespace std;
#include<time.h>
#include <Windows.h> 
int main1()
{
	/*����clock()������ʱ
	����Systemtime������ȡ����ʱ��:time
	ʱ��������:time_interval
	��ʱ��������keybd_event����ո��ɿ����ѵ���*/

	cout << "\t����clock()������ʱ��\n\t����:��ʱ��\n\tQQ:1310446718\n" << endl;

	//��¼����㿪ʱ��ʱ��time�����
	SYSTEMTIME time;		//�����������ȡϵͳʱ��
	GetLocalTime(&time);
	cout << time.wYear << "��" << time.wMonth << "��" << time.wDay << "��" << "����" << time.wDayOfWeek << endl;
	cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��" << time.wMilliseconds << "����" << "\n\n\n";

	clock_t start, finish;	//��ʼ����ʱ��
	double subtract;	//��¼��ֵ
	//int x, y;	//��¼�������

	//�Զ���ʱ����
	int time_interval;
	cout << "��ʱʱ����(����Ϊ��λ):" << endl;
	cin >> time_interval;

	//�����ʼ��ʱ��ʱ���
	GetLocalTime(&time);
	cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��" << time.wMilliseconds << "����" << "��ʼ����" << endl;

	start = clock();	//����while��ʼ��ʱ
	while (1)
	{
		finish = clock();	//��ͣ��ˢ�½���ʱ�䣬��������������if�ж�
		subtract = (double)(finish - start) / CLOCKS_PER_SEC;    //clock()���Ժ���Ϊ��λ����ʱ������Գ���CLOCKS_PER_SEC����time.h ���涨���һ������
		if (subtract == time_interval)
		{
			GetLocalTime(&time);		//����ʱ��������ȡϵͳʱ��
			cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��" << time.wMilliseconds << "΢��" << "  ���ѵ��� " << endl;

			//�ƶ���겻�ܷ�ֹ˯�ߣ�����ע�͵�
			//x = rand() % 801;
			//y = rand() % 601;
			//SetCursorPos(x, y);	//�ƶ����

			//���ÿո��ѵ���
			keybd_event(32, 0, 0, 0);//���¿ո�
			keybd_event(32, 0, KEYEVENTF_KEYUP, 0);//�ɿ��ո�

			start = clock();	//ˢ�½���ʱ�䣬���¼�ʱ
		}
	}

	system("pause");
	return 0;
}
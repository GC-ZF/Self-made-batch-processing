#include <iostream>
#include<windows.h>
#include<time.h>

using namespace std;

int main2() {
	/*����Sleep��ʱ
	����Systemtime������ȡ����ʱ��:time
	ʱ��������:time_interval
	��ʱ����������mouse_event������ɿ�������keybd_event����ո��ɿ�
	�������������д����ڣ��������ͣ�����Լ���keybd_event
	����ʹ�ÿո�Ҳ���Է�ֹ˯�ߣ�ֻ�ǵ��Գ����ʱ���ҿ��Կ����Ƿ�ִ�����������¼�
	ע��41��42����*/

	cout << "\t����sleep()������ʱ��\n\t����:��ʱ��\n\tQQ:1310446718\n" << endl;

	//��¼����ʱ��time�����
	SYSTEMTIME time;		//�����������ȡϵͳʱ��
	GetLocalTime(&time);
	cout << time.wYear << "��" << time.wMonth << "��" << time.wDay << "��" << "����" << time.wDayOfWeek << endl;
	cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��" << time.wMilliseconds << "����" << "\n\n\n";

	POINT p;
	GetCursorPos(&p);//��ȡ������� 

	//����ʱ����
	int time_interval;
	cout << "��ʱʱ����(����Ϊ��λ):" << endl;
	cin >> time_interval;
	time_interval = time_interval * CLOCKS_PER_SEC; //�뻻�����

	//�����ʼ��ʱ��ʱ���
	GetLocalTime(&time);
	cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��" << time.wMilliseconds << "΢��" << "  ��ʼ����" << endl;

	while (1)
	{
		Sleep(time_interval);
		//������¼� ��ֹ����˯��  ʹ���������
		//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//������
		//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ��Ҽ�
		//��������
	/*mouse_event(MOUSEEVENTF_LEFTDOWN, X * 65536 / 1024, Y * 65536 / 768, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, X * 65536 / 1024, Y * 65536 / 768, 0, 0);*/

	/*���������������cmd����������cout��䣬�޷�����ִ�У���Ҫ���س����߿ո�
	keybd_event���̵���¼�������ASCII�룬32:�ո� Ҳ����VK_Space*/
		keybd_event(32, 0, 0, 0);//���¿ո�
		keybd_event(32, 0, KEYEVENTF_KEYUP, 0);//�ɿ��ո�

		//������ʱ��
		GetLocalTime(&time);
		cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��" << time.wMilliseconds << "΢��" << "  ���ѵ��� " << endl;
	}

	return 0;
}
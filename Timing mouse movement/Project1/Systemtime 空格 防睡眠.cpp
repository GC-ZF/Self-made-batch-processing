#include <iostream> 
#include <Windows.h>  
#include<time.h>
using namespace std;

int main() {
	/*����Systemtime���������Ĳ�ֵ��ʱ:start,end
	����Systemtime������ȡ����ʱ��:time
	ʱ��������:time_interval		time_interval=start-end
	��ʱ��������keybd_event����ո��ɿ����ѵ���*/

	cout << "\t����SYSTEMTIME��ʱ��\n\t����:��ʱ��\n\tQQ:1310446718\n" << endl;

	//��¼����㿪ʱ��ʱ��time�����
	SYSTEMTIME time;
	GetLocalTime(&time);
	cout << time.wYear << "��"<<time.wMonth << "��" << time.wDay << "��" << "����" << time.wDayOfWeek << endl;
	cout << time.wHour << "ʱ" << time.wMinute << "��" << time.wSecond << "��"<< time.wMilliseconds << "����" <<"\n\n\n";

	//�Զ���ʱ����
	int time_interval;
	cout << "��ʱʱ����(����Ϊ��λ):" << endl;
	cin >> time_interval;

	//����start-end��¼ʱ����
	//���忪ʼʱ�����start
	SYSTEMTIME start;
	GetLocalTime(&start);
	int start_minute = start.wSecond;					//��¼����x��
	int start_second = start.wSecond;					//��¼����x��
	int start_milliseconds = start.wMilliseconds;		//��¼����x����

	//�������ʱ�����end
	SYSTEMTIME end;
	GetLocalTime(&end);
	//�����ʼ��ʱ��ʱ���
	cout << end.wHour << "ʱ" << end.wMinute << "��" << end.wSecond << "��" << end.wMilliseconds << "΢��" << "  ��ʼ����" << endl;

	//int x, y;  //��ʼ���������
	
	while (1)
	{
		GetLocalTime(&end);
		int end_minute = end.wSecond;					//��¼����ʱ��x��
		int end_second = end.wSecond;					//��¼����ʱ��x��
		int end_milliseconds = end.wMilliseconds;		//��¼����ʱ��x����
		//�����ӳ�
		/*cout <<"end\t"<< end_second << "��" << end_milliseconds << "΢��" << endl;
		cout<<"start\t"<< start_second << "��" << start_milliseconds << "΢��" << endl;*/

		int subtract = end_second - start_second;	//�����ֵ

		if (subtract < 0)	//ת��60����
		{
			subtract += 60;
		}

		//�����˶�ʱʱ�䣬�����жϣ���Ϊ��Ҫִ�������䣬10ms��ʱ����<10��������1000�����ڻ᲻ͣ�������ж�����
		if (subtract== time_interval && end_milliseconds<10)	
		{
			cout <<end.wHour<<"ʱ"<< end.wMinute<<"��"<< end.wSecond << "��" << end.wMilliseconds << "΢��" << "  ���ѵ��� " <<endl;

			//�ƶ���겻�ܷ�ֹ˯�ߣ�����ע�͵�
			/*x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);*/

			//���ÿո��ѵ���
			keybd_event(32, 0, 0, 0);//���¿ո�
			keybd_event(32, 0, KEYEVENTF_KEYUP, 0);//�ɿ��ո�

			GetLocalTime(&start);							//ˢ��startʱ��
			start_minute = start.wSecond;					//��¼����x��
			start_second = start.wSecond;					//��¼����x��
			start_milliseconds = start.wMilliseconds;		//��¼����x����
		}
	}

	system("pause");
	return 0;
}

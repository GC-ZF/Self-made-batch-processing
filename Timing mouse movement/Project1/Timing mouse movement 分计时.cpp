#include <iostream> 
#include <Windows.h>  
using namespace std;

int main() {
	//��¼����ʱ�䲢���
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << sys.wYear << "��";
	cout << sys.wMonth << "��";
	cout << sys.wDay << "��";
	cout << "����" << sys.wDayOfWeek << endl;
	cout << sys.wHour << "ʱ";
	cout << sys.wMinute << "��";
	cout << sys.wSecond << "��";
	cout << sys.wMilliseconds << "����" << endl;
	int start_minute = sys.wSecond;					//��¼����x��
	int start_second = sys.wSecond;					//��¼����x��
	int start_milliseconds = sys.wMilliseconds;		//��¼����x����

	//����ʱ�������end
	SYSTEMTIME end;
	int x, y;  //��ʼ���������
	int minute, second, milliseconds;//��¼ʱ���ֵ
	while (1)
	{
		GetLocalTime(&end);
		int end_minute = end.wSecond;					//��¼endʱ��x��
		int end_second = end.wSecond;					//��¼endʱ��x��
		int end_milliseconds = end.wMilliseconds;		//��¼endʱ��x����

		//ʱ���ֵ	60����
		minute = end_minute - start_minute;
		if (minute < 0)
		{
			minute += 60;
		}
		second = end_second - start_second;
		if (second < 0)
		{
			second += 60;
		}
		milliseconds = end_milliseconds - start_milliseconds;
		if (milliseconds < 1000)
		{
			milliseconds += 1000;
		}

		//��ʽ
		cout <<"end\t"<< end_second << "��" << end_milliseconds << "΢��" << endl;
		cout<<"start\t"<< start_second << "��" << start_milliseconds << "΢��" << endl;

		if (end_second - start_second == 10 && end_milliseconds < 10)	//�����������ӣ�ˢ�����λ�ã���Ϊ��10ms��ʱ����<10
		{
			cout << "�ƶ����"<<endl;
			x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);
			GetLocalTime(&sys);							//ˢ��startʱ��
			start_minute = sys.wSecond;					//��¼����x��
			start_second = sys.wSecond;					//��¼����x��
			start_milliseconds = sys.wMilliseconds;		//��¼����x����

			//����
			cout << "ˢ��"<<start_second << "��" << start_milliseconds << "΢��" << endl;
		}
	}

	system("pause");
	return 0;
}

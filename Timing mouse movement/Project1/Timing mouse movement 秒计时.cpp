#include <iostream> 
#include <Windows.h>  
using namespace std;

int main1() {
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
	while (1)
	{
		GetLocalTime(&end);
		int end_minute = end.wSecond;					//��¼ʱ����x��
		int end_second = end.wSecond;					//��¼ʱ����x��
		int end_milliseconds = end.wMilliseconds;		//��¼ʱ����x����
		/*cout <<"end\t"<< end_second << "��" << end_milliseconds << "΢��" << endl;
		cout<<"start\t"<< start_second << "��" << start_milliseconds << "΢��" << endl;*/
		if (fabs(end_second - start_second )== 10 && end_milliseconds<10)	//�����������ӣ�ˢ�����λ�ã���Ϊ��10ms��ʱ����<10
		{
			cout << "�ƶ����"<<endl;
			x = rand() % 801;
			y = rand() % 601;
			SetCursorPos(x, y);
			GetLocalTime(&sys);							//ˢ��startʱ��
			start_minute = sys.wSecond;					//��¼����x��
			start_second = sys.wSecond;					//��¼����x��
			start_milliseconds = sys.wMilliseconds;		//��¼����x����
			/*cout << "ˢ��"<<start_second << "��" << start_milliseconds << "΢��" << endl;*/
		}
	}

	system("pause");
	return 0;
}

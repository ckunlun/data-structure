#include <iostream>
using namespace std;
# include <math.h>
int main()
{
	unsigned int input;
	//int index = 0;
	int cnt = 0; //ֻ��3�Ժ��ֵ����֮ǰ��0����
	cin >> input;
	if (input >= 100000 || input < 1)
	{
		cout << "�������";
		return -1;
	}
	int temp = 3;
	for (int i = 5; i <= input; i += 2) //���ҳ�С������ֵ������������
	{
		int j = 3;
		int up = (int)sqrt(i) + 1;
		for (; j < up; j += 1)
		{
			if (i % j == 0)
			{
				break;
			}

		}
		if (j == up ) //iΪ����
		{
			if ((i - temp) == 2)
			{
				cnt++;
				//cout << i << "  " << temp << endl;
			}

			temp = i;
		}
	}
	cout << cnt;
	return 0;
}



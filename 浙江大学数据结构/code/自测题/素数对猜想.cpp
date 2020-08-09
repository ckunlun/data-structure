#include <iostream>
using namespace std;
# include <math.h>
int main()
{
	unsigned int input;
	//int index = 0;
	int cnt = 0; //只找3以后的值。三之前有0个。
	cin >> input;
	if (input >= 100000 || input < 1)
	{
		cout << "输入错误";
		return -1;
	}
	int temp = 3;
	for (int i = 5; i <= input; i += 2) //查找出小于输入值的所有素数。
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
		if (j == up ) //i为素数
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



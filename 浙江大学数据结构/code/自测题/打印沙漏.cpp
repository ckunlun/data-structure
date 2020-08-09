#include <iostream>
using namespace std;
int main()
{
	// 利用等差数列公式计算。
	unsigned char sigmoid = '0';
	short int cnt = 0;
	int sum = 0;
	cin >> cnt;
	cin >> sigmoid;
	if (cnt == 0 || cnt > 1000)
	{
		cout << "输入不符合要求，程序退出。" << endl;
		return -1;
	}

	//等差数列的项数和行数一一对应。
	int row;
	int tempCnt = (int)((cnt - 1) / 2);

	for (row = 1; row * (row + 2) <= tempCnt; row++)
	{
	}
	row--;

	for (int j = row; j > 0; j--)
	{
		//打印空格
		for (int i = 0; i < row - j; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 2 * j + 1; i++) // 打印符号
		{
			cout << sigmoid;
			sum++;
		}
		cout << endl;
	}


	//打印最中间的行
	int j = 0;
	for (int i = 0; i < row - j; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < 2 * j + 1; i++) // 打印符号
	{
		cout << sigmoid;
		sum++;
	}
	cout << endl;



	for (int j = 1; j <= row; j++)
	{
		//打印空格
		for (int i = 0; i < row - j; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 2 * j + 1; i++) // 打印符号
		{
			cout << sigmoid;
		}
		cout << endl;
	}

	cout << cnt - (row * (row + 2) * 2 + 1);

	return 0;
}



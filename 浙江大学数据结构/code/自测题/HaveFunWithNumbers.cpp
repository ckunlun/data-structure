#include <iostream>
using namespace std;

//程序有限制，输入数据不能大于(2^64 - 1) / 2;

// 利用循环获取输入数据的位数
int cntDigits(unsigned long long input)
{
	unsigned long long temp = input;
	int digits = 0;
	while (temp)
	{
		temp = temp / 10;
		digits++;
	}
	return digits;
}

// 将输入数据按位转换成升序数组。
void sortInput(unsigned long long input, int digits, int* array)
{
	unsigned long long temp = input;

	// 输入数据按位转换成数组
	for (int i = 0; i < digits; i++)
	{
		array[i] = temp % 10;
		temp = temp / 10;		
	}
	//for (int i = 0; i < digits; i++)
	//{
	//	cout << "排序前：input: " << array[i] << endl;
	//}

	// 排序（冒泡排序）
	for (int i = 0; i < digits; i++)
	{
		for (int j = 0; j < digits - i - 1; j++)
		{
			int min = 0;
			if (array[j] > array[j + 1])
			{
				min = array[j + 1];
				array[j + 1] = array[j];
				array[j] = min;

			}
		}
	}
	//for (int i = 0; i < digits; i++)
	//{
	//	cout << "排序后：input: " << array[i] << endl;
	//}

}

// 对比输入的两个数组是否一样，一样返回1
int compare(int* array1, int* array2, int length)
{
	int tag = 1;
	for (int i = 0; i < length; i++)
	{
		if (array1[i] != array2[i])
		{
			tag = 0;
			break;
		}
	}
	return tag;
}
int main()
{
	unsigned long long input; //输入
	unsigned long long output; //输出
	
	cin >> input;
	if (input > pow(10, 20) - 1)
	{
		cout << "input error!";
	}

	output = input * 2;

	// 分别获取input和output的位数
	int inputDigits = cntDigits(input); //输入数据的位数
	int outputDigits = cntDigits(output); //输出数据的位数

	if (inputDigits == outputDigits) //如果输入输出位数相等，做判断，否则直接输出数据。
	{
		int* inputArray = new int[inputDigits];
		int* outputArray = new int[outputDigits];

		sortInput(input, inputDigits, inputArray);
		sortInput(output, outputDigits, outputArray);



		if (compare(inputArray, outputArray, inputDigits)) //对比两个输入是否一致，一致返回1，否则返回0
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		
	}
	else
	{
		cout << "No" << endl;
	}
	cout << input * 2;
	return 0;
}



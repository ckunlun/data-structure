#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 21 //最大长度应该是21，后面有个结束字符。
// 对比输入的两个数组是否一样，一样返回1
int compare(char* array1, char* array2, int length)
{
	// 排序（冒泡排序）
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			char min = 0;
			if (array1[j] > array1[j + 1])
			{
				min = array1[j + 1];
				array1[j + 1] = array1[j];
				array1[j] = min;

			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			char min = 0;
			if (array2[j] > array2[j + 1])
			{
				min = array2[j + 1];
				array2[j + 1] = array2[j];
				array2[j] = min;

			}
		}
	}
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
	char input[MAXSIZE] = { 0, };
	char output[MAXSIZE + 1] = { 0, };
	cin >> input;
	int tag = 0;
	for (int i = strlen(input) - 1; i >= 0; i--)
	{
		if (input[i] - '0' < 5)
		{
			int temp = (input[i] - '0') * 2 + tag;
			output[i + 1] = temp + '0';
			tag = 0;
		}
		else
		{
			int temp = (((input[i] - '0') * 2) % 10) + tag;
			output[i + 1] = temp + '0';
			tag = 1;
		}
		
	}
	if (tag == 1)
	{
		output[0] = tag + '0';
		cout << "No" << endl;
		cout << output;
	}
	else
	{
		char inputTemp[MAXSIZE] = { 0, };
		char outputTemp[MAXSIZE] = { 0, };
		for (int i = 0; i < strlen(input); i++)
		{
			inputTemp[i] = input[i];
			outputTemp[i] = output[i + 1];
		}
		if (compare(inputTemp, outputTemp, strlen(input)))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		for (int i = 1; i <= strlen(input); i++)
			cout << output[i];
	}

	
	return 0;
}
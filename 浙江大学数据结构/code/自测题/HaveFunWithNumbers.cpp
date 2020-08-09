#include <iostream>
using namespace std;

//���������ƣ��������ݲ��ܴ���(2^64 - 1) / 2;

// ����ѭ����ȡ�������ݵ�λ��
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

// ���������ݰ�λת�����������顣
void sortInput(unsigned long long input, int digits, int* array)
{
	unsigned long long temp = input;

	// �������ݰ�λת��������
	for (int i = 0; i < digits; i++)
	{
		array[i] = temp % 10;
		temp = temp / 10;		
	}
	//for (int i = 0; i < digits; i++)
	//{
	//	cout << "����ǰ��input: " << array[i] << endl;
	//}

	// ����ð������
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
	//	cout << "�����input: " << array[i] << endl;
	//}

}

// �Ա���������������Ƿ�һ����һ������1
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
	unsigned long long input; //����
	unsigned long long output; //���
	
	cin >> input;
	if (input > pow(10, 20) - 1)
	{
		cout << "input error!";
	}

	output = input * 2;

	// �ֱ��ȡinput��output��λ��
	int inputDigits = cntDigits(input); //�������ݵ�λ��
	int outputDigits = cntDigits(output); //������ݵ�λ��

	if (inputDigits == outputDigits) //����������λ����ȣ����жϣ�����ֱ��������ݡ�
	{
		int* inputArray = new int[inputDigits];
		int* outputArray = new int[outputDigits];

		sortInput(input, inputDigits, inputArray);
		sortInput(output, outputDigits, outputArray);



		if (compare(inputArray, outputArray, inputDigits)) //�Ա����������Ƿ�һ�£�һ�·���1�����򷵻�0
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



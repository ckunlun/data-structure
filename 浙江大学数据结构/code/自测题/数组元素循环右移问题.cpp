#include <iostream>
using namespace std;

int main()
{
	int N = 0; //����Ԫ�ص��ܸ���
	int M = 0; //������λ�ĸ���

	cin >> N >> M; 

	int* array = new int[N]; //��������
	
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}

	for (int j = 0; j < M; j++)
	{
		int temp = array[0];
		array[0] = array[N - 1];
		for (int i = N - 1; i > 1; i--)
		{
			array[i] = array[i - 1];
		}
		array[1] = temp;
	}
	// �������
	for (int i = 0; i < N - 1; i++)
	{
		cout << array[i] << " ";
	}
	cout << array[N - 1];

	delete[] array;

	return 0;
}



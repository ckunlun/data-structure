//������к�����
//���룺��һ���������и���N���ڶ�������N������������Կո�ָ�
//�������һ�������������кͣ��������������������Ϊ�����������0��

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//��������ʱ��
clock_t start, stop;
double duration;
int myMax(int a, int b, int c);
int function1(int* iArray, int iCnt);//����1��ʱ�临�Ӷ�Ϊn^3
int function2(int* iArray, int iCnt);//����2��ʱ�临�Ӷ�Ϊn^2
int function3(int* iArray, int iLeft, int iRight);//����3���η���ʱ�临�Ӷ�Ϊnlogn
int function4(int* iArray, int iCnt);//����4���ߴ���ʱ�临�Ӷ�Ϊn

int main()
{
	int iCnt = 0;//�������еĸ���
	int iMax = 0;//������õ����ֵ
	int* ipNum = NULL;//�洢���������

	scanf("%d", &iCnt);//�������л�ȡ���еĸ���

	if ((ipNum = (int*)(calloc(iCnt, sizeof(int)))) == NULL)
	{
		printf("�ڴ�����ʧ��!\n");
	}
	//scanf��������ʱ���Զ��Կո���Ϊ�ָ������������ո�
	//��scanf������������ʱ������Ҫ���ǿհ����ַ��Ĵ��ڣ��ո����񣬻��У�
	for (int i = 0; i < iCnt; i++)
	{
		scanf("%d", &ipNum[i]);//�������л�ȡ����
		/*
		//�ٶȵķ���
		while (scanf("%d",&arr[numdoll]) != EOF && getchar() != '\n')
			numdoll++;
		//ѭ����������������ݣ����Կո�ָ���
		*/
	}

	/*for (int i = 0; i < iCnt; i++)//�������������Ƿ���ȷ
	{
		printf("%d\n", ipNum[i]);
	}*/

	//start = clock();//��ʼ��ʱ
	iMax = function3(ipNum, 0, iCnt);//ʵ�ַ���3�ĺ���
//	stop = clock();
	printf("%d\n", iMax);
	return 0;
}

int myMax(int a, int b, int c)
{
	return (a > b ? a : b > c ? b : c);
}
int function1(int* iArray, int iCnt)
{
	int iMax = 0, iCurMax = 0;
	for (int i = 0; i < iCnt; i++)
	{
		for (int j = i; j < iCnt; j++)
		{
			iCurMax = 0;
			for (int k = i; k <= j; k++)
			{
				iCurMax += iArray[k];
				if (iCurMax > iMax)
				{
					iMax = iCurMax;
				}
			}
		}
	}
	return iMax;
}

int function2(int* iArray, int iCnt)
{
	int iMax = 0, iCurMax = 0;
	for (int i = 0; i < iCnt; i++)
	{
		iCurMax = 0;
		for (int j = i; j < iCnt; j++)
		{
			iCurMax += iArray[j];
			if (iCurMax > iMax)
			{
				iMax = iCurMax;
			}
		}
	}
	return iMax;
}

int function3(int* iArray, int iLeft, int iRight)
{
	if ((iRight - iLeft) == 1)
	{
		return iArray[iLeft];
	}
	int iMid = (iLeft + iRight) / 2;

	int iLeftMax = function3(iArray, iLeft, iMid);
	int iRightMax = function3(iArray, iMid, iRight);

	//���м�λ�����������ֵ
	int iLeftBondMax = 0, iMax = 0;
	for (int i = iMid; i >= iLeft; i--)
	{
		iLeftBondMax += iArray[i];
		if (iLeftBondMax > iMax)
		{
			iMax = iLeftBondMax;
		}
	}
	iLeftBondMax = iMax;
	iMax = 0;
	//���м�λ�����������ֵ
	int iRightBondMax = 0;
	for (int i = iMid + 1; i < iRight; i++)
	{
		iRightBondMax += iArray[i];
		if (iRightBondMax > iMax)
		{
			iMax = iRightBondMax;
		}
	}
	iRightBondMax = iMax;
	//�������������ֵ
	int iMidMax = iRightBondMax + iLeftBondMax;

	return myMax(iMidMax, iRightMax, iLeftMax);

}

int function4(int* iArray, int iCnt)//���ߴ���
{
	int iMax = 0, iCurMax = 0;
	for (int i = 0; i < iCnt; i++)
	{
		iCurMax += iArray[i];
		if (iCurMax > iMax)
		{
			iMax = iCurMax;
		}
		if (iCurMax < 0)
		{
			iCurMax = 0;
		}
	}
	return iMax;
}
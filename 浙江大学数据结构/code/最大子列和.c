//最大子列和问题
//输入：第一行输入子列个数N，第二行输入N个整数，其间以空格分隔
//输出：在一行中输出最大子列和，如果序列中所有整数皆为负数，则输出0；

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//计算运行时间
clock_t start, stop;
double duration;
int myMax(int a, int b, int c);
int function1(int* iArray, int iCnt);//方法1，时间复杂度为n^3
int function2(int* iArray, int iCnt);//方法2，时间复杂度为n^2
int function3(int* iArray, int iLeft, int iRight);//方法3分治法，时间复杂度为nlogn
int function4(int* iArray, int iCnt);//方法4在线处理，时间复杂度为n

int main()
{
	int iCnt = 0;//输入数列的个数
	int iMax = 0;//计算求得的最大值
	int* ipNum = NULL;//存储输入的序列

	scanf("%d", &iCnt);//从命令行获取数列的个数

	if ((ipNum = (int*)(calloc(iCnt, sizeof(int)))) == NULL)
	{
		printf("内存申请失败!\n");
	}
	//scanf函数输入时，自动以空格作为分隔符，不会读入空格。
	//在scanf函数输入数据时，不需要考虑空白类字符的存在（空格，跳格，换行）
	for (int i = 0; i < iCnt; i++)
	{
		scanf("%d", &ipNum[i]);//从命令行获取数据
		/*
		//百度的方法
		while (scanf("%d",&arr[numdoll]) != EOF && getchar() != '\n')
			numdoll++;
		//循环读入多组整型数据，都以空格分隔。
		*/
	}

	/*for (int i = 0; i < iCnt; i++)//测试输入数据是否正确
	{
		printf("%d\n", ipNum[i]);
	}*/

	//start = clock();//开始计时
	iMax = function3(ipNum, 0, iCnt);//实现方法3的函数
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

	//从中间位置向左找最大值
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
	//从中间位置向右找最大值
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
	//计算总序列最大值
	int iMidMax = iRightBondMax + iLeftBondMax;

	return myMax(iMidMax, iRightMax, iLeftMax);

}

int function4(int* iArray, int iCnt)//在线处理
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
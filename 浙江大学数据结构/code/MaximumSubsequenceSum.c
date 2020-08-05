//Maximum Subsequence Sum 
//输入：第一行输入子列个数N，第二行输入N个整数，其间以空格分隔
//输出：在一行中第一个输出为最大子列和，第二个输出为最大子序列的第一个数，
//第三个输出为最大子序列的最后一个数，如果序列中所有整数皆为负数，则输出0和
//原始序列的第一个和最后一个数。
//存在问题：并列和对应相同i但是不同j，即尾是0 项编译不过
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

time_t start, end;
double duration;
int maxSubsequenceSum(int iArray[], int iCnt, int* ipFirstNum, int* ipLastNum);

int main()
{
	int iCnt = 0, iMax = 0, iFirstNum = 0, iLastNum = 0;
	int* ipNum = NULL;
	start = 0, end = 0, duration = 0;//为计时变量赋初值

	scanf("%d", &iCnt);

	if ((ipNum = (int*)calloc(iCnt, sizeof(int))) == NULL)
	{
		printf("内存分配失败！");
		exit(0);
	}
	for (int i = 0; i < iCnt; i++)
	{
		scanf("%d", &ipNum[i]);
	}

	start = clock();
	iMax = maxSubsequenceSum(ipNum, iCnt, &iFirstNum, &iLastNum);
	end = clock();
	duration = ((double)(end - start)) / CLK_TCK;//计算程序运行时间

	printf("%d %d %d\n", iMax, iFirstNum, iLastNum);
	getchar();

	return 0;
}

int maxSubsequenceSum(int iArray[], int iCnt, int* ipFirstNum, int* ipLastNum)
{
	int iCurMax=0, iMax = 0, iFirstNum = 0, iLastNum = 0, iInd=0;
	int iFlagNeg = 0, iFlagZero = 0;
	
	iFirstNum = iArray[0];
	for (int i = 0; i < iCnt; i++)
	{
		iCurMax += iArray[i];
		if (iArray[i] == 0)
		{
			iFlagZero++;
		}
		if (iArray[i] < 0)
		{
			iFlagNeg++;
		}
		if (iCurMax >= iMax)
		{
			if (iArray[i] == 0)
			{
				iMax = iCurMax;
				iLastNum = iArray[i];
				iInd = i;
			}
			else if (iCurMax > iMax)
			{
				iMax = iCurMax;
				iLastNum = iArray[i];
				iInd = i;
			}
		}
		if (iCurMax < 0)
		{
			iCurMax = 0;
			if (i + 1 < iCnt && i <= iInd)
			{
				if (iArray[i] < 0)
				{
					iFirstNum = iArray[i + 1];
				//	iArray[i] = 0;
				}
			}
			else
			{
				continue;
			}
		}
	}

	if (iMax == 0)
	{
		iFirstNum = iArray[0];
		iLastNum = iArray[iCnt-1];
		if ((iFlagNeg + iFlagZero) == iCnt && iFlagNeg < iCnt)
		{
			iFirstNum = 0;
			iLastNum = 0;
		}
	}

	*ipFirstNum = iFirstNum;
	*ipLastNum = iLastNum;
	return iMax;
}
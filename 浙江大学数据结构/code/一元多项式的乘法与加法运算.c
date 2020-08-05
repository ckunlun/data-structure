/*
一元多项式的乘法与加法运算
输入格式：
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一
个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};
Polynomial ReadPoly();//读取行列式
Polynomial Mult(Polynomial P1, Polynomial P2);//行列式相乘
Polynomial Add(Polynomial P1, Polynomial P2);//行列式相加
Polynomial Insert(int c, int e, Polynomial P);//往链表中按照指数递减次序插入值
void PrintPoly(Polynomial PP);//显示行列式
void Attach(int c, int e, Polynomial* P);//往链表后面附加
int Compare(int a, int b);
int main()
{
	Polynomial P1, P2, PP, PS;

	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	PS = Add(P1, P2);
	PrintPoly(PS);

	return 0;
}
Polynomial ReadPoly()//读取行列式
{
	Polynomial P, pRear, t;
	if ((P = (Polynomial)malloc(sizeof(struct PolyNode))) == NULL)
	{
		printf("分配内存空间错误！");
		exit(0);
	}
	P->link = NULL;
	pRear = P;
	int iCnt;
	int c, e;
	scanf("%d", &iCnt);
	while (iCnt--)
	{
		scanf("%d %d", &c, &e);
		Attach(c, e, &pRear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}
void PrintPoly(Polynomial P)
{
	if (!P)
	{
		printf("NULL");
		return;
	}
	int flag = 0;
	for (; P; P = P->link)
	{
		if (flag == 0)
		{
			flag = 1;
		}
		else
		{
			printf(" ");
		}
		printf("%d %d", P->coef, P->expon);
	}
	printf("\n");
}
void Attach(int c, int e, Polynomial* P)//往链表后面附加结点
{
	Polynomial pTemp;
	if ((pTemp = (Polynomial)malloc(sizeof(struct PolyNode))) == NULL)
	{
		printf("分配内存空间错误！");
		exit(0);
	}
	pTemp->coef = c;
	pTemp->expon = e;
	pTemp->link = NULL;
	(*P)->link = pTemp;
	*P = pTemp;
}
int Compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
Polynomial Mult(Polynomial P1, Polynomial P2)//未实现以指数递减输出
{
	if (!P1 || !P2) return NULL;

	Polynomial P, front, rear, t;
	if ((P = (Polynomial)malloc(sizeof(struct PolyNode))) == NULL)
	{
		printf("分配内存空间错误！");
		exit(0);
	}
	rear = P;
	int c, e;
	front = P2;
	if (P1)//用P1的第一项依次成P2的各项
	{
		for (; P2; P2 = P2->link)
		{
			c = P1->coef * P2->coef;
			e = P1->expon + P2->expon;
			Attach(c, e, &rear);
		}
		P2 = front;
		P1 = P1->link;
	}
	t = P;//记录P的第一个头位置
	P = P->link;
	free(t);
	for (; P1; P1 = P1->link)
	{
		for (; P2; P2 = P2->link)
		{
			c = P1->coef * P2->coef;
			e = P1->expon + P2->expon;
			P = Insert(c, e, P);//在链表中插入值

		}
		P2 = front;
	}
	return P;
}

Polynomial Add(Polynomial P1, Polynomial P2)//行列式相加
{
	if (!P1 || !P2) return NULL;

	Polynomial P, front, rear;
	if ((P = (Polynomial)malloc(sizeof(struct PolyNode))) == NULL)
	{
		printf("分配内存空间错误！");
		exit(0);
	}
	rear = P;
	while (P1 && P2)
	{
		switch (Compare(P1->expon, P2->expon))
		{
		case 1:
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1:
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
			break;
		case 0:
			int sum = P1->coef + P2->coef;
			if (sum)
			{
				Attach(sum, P2->expon, &rear);
			}
			P1 = P1->link;
			P2 = P2->link;
			break;
		}
	}
	for (; P1; P1 = P1->link)
	{
		Attach(P1->coef, P1->expon, &rear);
	}
	for (; P2; P2 = P2->link)
	{
		Attach(P2->coef, P2->expon, &rear);
	}
	front = P;
	P = P->link;
	free(front);
	return P;
}

Polynomial Insert(int c, int e, Polynomial P)
{
	if (!P) return NULL;
	Polynomial pTemp, pCopy, pNew, t;
	if ((pNew = (Polynomial)malloc(sizeof(struct PolyNode))) == NULL)
	{
		printf("分配内存空间错误！");
		exit(0);
	}
	pNew->coef = c;
	pNew->expon = e;
	pNew->link = NULL;
	pTemp = P;
	pCopy = P;
	while (P && e < P->expon)
	{
		pCopy = P;
		P = P->link;
	}
	if (P)
	{
		if (e == P->expon)
		{
			P->coef = c + P->coef;
			if (P->coef == 0)//系数为0则删除此结点
			{
				t = P;
				pCopy->link = P->link;
				free(t);
			}
		}
		else
		{
			pCopy->link = pNew;
			pNew->link = P;
		}

	}
	else
	{

		pCopy->link = pNew;
		pNew->link = NULL;
	}

	return pTemp;
}
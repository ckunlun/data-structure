#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define KEYLENGTH 11//关键字字符串最大长度
typedef char ElementType[KEYLENGTH + 1];//关键字类型用字符串
typedef int Index;//散列地址类型
#define MAXTABLESIZE 1000000
#define MAXD 5
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
	int Count;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode* HashTable;
struct TblNode {//散列表结点定义
	int TableSize;//表的最大长度
	List Heads;//指向链表头结点的数组
};
HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	for (i = 0; i < H->TableSize; i++) {
		H->Heads[i].Data[0] = '\0'; H->Heads[i].Next = NULL;
		H->Heads[i].Count = 0;
	}
	return H;
}

Position Find(HashTable H, ElementType Key)
{
	Position P;
	Index Pos;
	/* 初始散列位置*/
	Pos = Hash(atoi(Key+KEYLENGTH-MAXD), H->TableSize);
	P = H->Heads[Pos].Next; /* 从该链表的第1个结点开始*/
	/* 当未到表尾，并且Key未找到时*/
	while (P && strcmp(P->Data, Key))
		P = P->Next;
	return P; /* 此时P或者指向找到的结点，或者为NULL */
}
int NextPrime(int N)
{ /* 返回大于N且不超过MAXTABLESIZE的最小素数*/
	int i, p = (N % 2) ? N + 2 : N + 1; /*从大于N的下一个奇数开始*/
	while (p <= MAXTABLESIZE) {
		for (i = (int)sqrt(p); i > 2; i--)
			if (!(p % i)) break; /* p不是素数*/
		if (i == 2) break; /* for正常结束，说明p是素数*/
		else p += 2; /* 否则试探下一个奇数*/
	}
	return p;
}

int Hash(int Key, int P)
{ /* 除留余数法法散列函数*/
	return Key % P;
}

void ScanAndOutput(HashTable H)
{
	int PCnt;
	int i, MaxCnt = PCnt = 0;
	ElementType MinPhone;
	List Ptr;
	MinPhone[0] = '\0';
	for (i = 0; i < H->TableSize; i++)//扫描链表
	{
		Ptr = H->Heads[i].Next;
		while (Ptr)
		{
			if (Ptr->Count > MaxCnt)//更新最大通话次数
			{
				MaxCnt = Ptr->Count;
				strcpy(MinPhone, Ptr->Data);
				PCnt = 1;
			}
			else if (Ptr->Count == MaxCnt)
			{
				PCnt++;//狂人计数
				if (strcmp(MinPhone, Ptr->Data) > 0)
					strcpy(MinPhone, Ptr->Data);//更新狂人的最小手机号码
			}
			Ptr = Ptr->Next;
		}
	}
	printf("%s %d", MinPhone, MaxCnt);
	if (PCnt > 1)
		printf("%d", PCnt);
	printf("\n");
}
bool Insert(HashTable H, ElementType Key)
{
	Position P, NewCell;
	Index Pos;
	P = Find(H, Key);
	if (!P) { /* 关键词未找到，可以插入*/
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		NewCell->Count = 1;
		Pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);
		/* 将NewCell插入为H->Heads[Pos]链表的第1个结点*/
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else { /* 关键词已存在*/
		P->Count++;
		return false;
	}
}

int main()
{
	int N, i;
	ElementType Key;
	HashTable H;

	scanf("%d", &N);
	H = CreateTable(N * 2);//创建一个散列表
	for (i = 0; i < N; i++)
	{
		scanf("%s", Key); Insert(H, Key);
		scanf("%s", Key); Insert(H, Key);
	}
	ScanfAndOutput(H);//扫描整个散列表
	DestroyTable(H);
	return 0;
}
/*
程序功能：构建haffumanTree并实现huffman编码,, 存在问题。
*/
#include<stdio.h>
#include<stdlib.h>

#define MINDATA 0 //该值应根据具体情况定义为小于所有权重的值
#define MAXLENGTH 100//码流最大长度为100
typedef struct TreeNode* HuffmanTree;
typedef HuffmanTree ElementType;
typedef struct HNode* MinHeap;
HuffmanTree DeleteMin(MinHeap H);//删除最小堆中的最小值，返回值为HuffmanTree
void BuildMinHeap(MinHeap H);//将H->Element[]按权值调整为最小堆
void Insert(MinHeap H, ElementType T);//在H中插入T。
HuffmanTree Huffman(MinHeap H);//创建Huffman树
void PercDown(MinHeap H, int i);//下滤，将H中以H->Data[p]为根的子堆调整为最小堆
bool IsEmpty(MinHeap H);
bool IsFull(MinHeap H);
MinHeap CreateHeap(int MaxSize);//创建容量为MaxSize的空最大堆
HuffmanTree CreateHuffmanTree(int Weight);//创建HuffmanTree，其中Left和Right指向NULL
void enCode(HuffmanTree T, int* i, unsigned char* code);//利用HuffmanTree返回Huffman编码数组。
void Assign(HuffmanTree tar, HuffmanTree ori);//huffmanTree的赋值
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};
struct HNode {
	ElementType* Data;//存储元素的数组,为TreeNode型数组
	int Size;//堆中当前元素个数
	int Capacity;//堆的最大容量
};
void PreOrderPrintLeaves(HuffmanTree BT)//输出Huffman树的所有叶子节点
{
	if (BT) {
		if (!BT -> Left && !BT->Right)
			printf(" % d", BT->Weight);
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}
int main()
{
	MinHeap H;
	HuffmanTree T;
	int iSize, iWeight;
	unsigned char* code = (unsigned char*)malloc(sizeof(unsigned char) * MAXLENGTH);
	iSize = 0;
	iWeight = 0;
	int n = 0;
	scanf("%d", &iSize);
	H = CreateHeap(iSize);//创建堆
	for (int i = 0; i < iSize; i++)//为创建的堆插入值
	{
		scanf("%d", &iWeight);

		T = CreateHuffmanTree(iWeight);
		Assign(H->Data[i + 1], T);
		H->Size++;
		free(T);

	}
	for (int i = 0; i <= iSize; i++)
	{
		printf("%d", H->Data[i]->Weight);
	}
	printf("\n");
	T=Huffman(H);//创建Huffman树
	PreOrderPrintLeaves(T);
	printf("\n-------\n");
	enCode(T, &n, code);
	return 0;
}
void Assign(HuffmanTree tar, HuffmanTree ori)
{
	if(tar == NULL)
		tar = (HuffmanTree)malloc(sizeof(struct TreeNode));
	tar->Left = ori->Left;
	tar->Right = ori->Right;
	tar->Weight = ori->Weight;
}
HuffmanTree CreateHuffmanTree(int Weight)//创建HuffmanTree，其中Left和Right指向NULL
{
	HuffmanTree T;
	T = (HuffmanTree)malloc(sizeof(struct TreeNode));
	T->Left = T->Right = NULL;
	T->Weight = Weight;
	return T;
}
MinHeap CreateHeap(int MaxSize)//创建容量为MaxSize的空最大堆
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType) * (MaxSize + 1));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0]= (HuffmanTree)malloc(sizeof(struct TreeNode));
	H->Data[0]->Left = NULL;
	H->Data[0]->Right = NULL;
	H->Data[0]->Weight = MINDATA;
	for (int i = 1; i <= MaxSize; i++)
	{
		H->Data[i] = (HuffmanTree)malloc(sizeof(struct TreeNode));
		H->Data[i]->Left = NULL;
		H->Data[i]->Right = NULL;
		H->Data[i]->Weight = MINDATA;
	}

	return H;
}

bool IsEmpty(MinHeap H)
{
	return (H->Size == 0);
}
bool IsFull(MinHeap H)
{
	return (H->Size == H->Capacity);
}


HuffmanTree Huffman(MinHeap H)  //H中存储了size个HuffmanTree节点
{//假设H->Size个权值已存在在H->Element[]->Weight里
	int i;
	HuffmanTree T;
	BuildMinHeap(H);//将H->Element[]按权值调整为最小堆

	for (i = 1; i <= H->Size; i++)//做H->Size-1次合并
	{
		T = (HuffmanTree)malloc(sizeof(struct TreeNode));//建立新结点
		T->Left = (HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Right = (HuffmanTree)malloc(sizeof(struct TreeNode));
		Assign(T->Left, DeleteMin(H));
		Assign(T->Right, DeleteMin(H));
		for (int i = 0; i <= 3; i++)
		{
			printf("%d", H->Data[i]->Weight);
		}
		printf("\n");
		T->Weight = T->Left->Weight + T->Right->Weight;//计算新权值
		printf("left=%d,right=%d\n", T->Left->Weight, T->Right->Weight);
		Insert(H, T);//将新T插入最小堆

	}
	T = (HuffmanTree)malloc(sizeof(struct TreeNode));//建立新结点
	Assign(T, DeleteMin(H));
	PreOrderPrintLeaves(T);
	printf("\n-------\n");
	return T;
}


HuffmanTree DeleteMin(MinHeap H)//从最小堆H中取出节点Weight值最小的元素，
//并删除一个节点
{
	if (IsEmpty(H))
	{
		printf("最小堆已为空\n");
		exit(0);
	}

	int Parent, Child;
	ElementType MinItem, X;
	MinItem = (HuffmanTree)malloc(sizeof(struct TreeNode));//建立新结点
	X = (HuffmanTree)malloc(sizeof(struct TreeNode));//建立新结点
	Assign(MinItem, H->Data[1]);
	//用最小堆中最后一个元素从根结点开始向上过滤下层结点
	//X = H->Data[H->Size--];//注意当前堆的规模要减小
	Assign(X, H->Data[H->Size--]);//注意当前堆的规模要减小
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child]->Weight > \
			H->Data[Child + 1]->Weight))
			Child++;//Child指向作于结点较小的
		if (X->Weight < H->Data[Child]->Weight) break;
		else
			Assign(H->Data[Parent], H->Data[Child]);
	}
	Assign(H->Data[Parent], X);
	return MinItem;
}

void BuildMinHeap(MinHeap H)//将H->Element[]按权值调整为最小堆
{//调整H->Data[]中的元素，是满足最小堆的有序性
 //这里假设所有H->Size个元素已经存H->Data[]中
	int i;
	
	//从最后一个结点的父节点开始，到根节点
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);

}
void PercDown(MinHeap H, int i)
{
	int Parent, Child;
	ElementType X;
	X = (HuffmanTree)malloc(sizeof(struct TreeNode));//建立新结点
	Assign(X, H->Data[i]);

	for (Parent = i; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child]->Weight > \
			H->Data[Child + 1]->Weight))
			Child++;//Child指向作于结点较小的
		if (X->Weight < H->Data[Child]->Weight) break;
		else
			Assign(H->Data[Parent], H->Data[Child]);
	}
	Assign(H->Data[Parent], X);
}
void Insert(MinHeap H, ElementType T)//在H中插入T。//存在问题，无法将值传入。明天需要重新写。
{//将元素X插入最小堆H，其中H->Data[0]已经定义为哨兵
	int i;
	if (IsFull(H))
	{
		printf("最小堆已满");
		exit(0);
	}
	i = ++H->Size;//i指向插入后堆中的最后一个元素的位置

	for (; H->Data[i / 2]->Weight > T->Weight; i /= 2)
		Assign(H->Data[i], H->Data[i / 2]);//上滤

	Assign(H->Data[i], T);

}

/*void enCode(HuffmanTree T, unsigned char* code, int iSize)//利用HuffmanTree返回Huffman编码数组。
{
	HuffmanTree temp = T;
	int* cnt = (int*)malloc(sizeof(int) * iSize);
	int i = 0;
	
}*/
void enCode(HuffmanTree T, int* i, unsigned char* code)//打印HuffmanTree返回Huffman编码数组。
{
	if (T)
	{
		if ((T->Left == NULL) && (T->Right == NULL))
		{
			printf("%d: ",T->Weight);
			for (int j = 0; j < (*i) - 1; j++)
				printf("%d", code[j]);
			printf("\n");
		}
		else
		{
			code[(*i)++] = 0;
			enCode(T->Left, i, code);
			code[(*i)-1] = 1;
			enCode(T->Right, i, code);
		}


	}
}
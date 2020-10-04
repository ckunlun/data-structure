/*
 * @Author: your name
 * @Date: 2020-02-07 17:02:29
 * @LastEditTime: 2020-09-29 21:19:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinedd:\study\c&c++\数据结构\浙江大学数据结构\code\树的同构.c
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
	int N, i; //二叉树的节点个数
	char cl, cr;
	Tree Root = Null;
	int check[MaxTree] = {0};
	scanf("%d\n", &N);

	if (N)
	{
		for (i = 0; i < N; i++)
			check[i] = 0; //初始化
		for (i = 0; i < N; i++)
		{
			scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
			{
				T[i].Left = Null;
			}
			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
			{
				T[i].Right = Null;
			}
		}
		for (i = 0; i < N; i++)
			if (!check[i])
				break;

		Root = i;
	}
	return Root;
}
int Isomorphic(Tree R1, Tree R2)
{
	if ((R1 == Null) && (R2 == Null)) //都为空
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0; //两个中有一个为空
	if (T1[R1].Element != T2[R2].Element)
		return 0;										//根不一样
	if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) //根结点的左节点都为空
		return Isomorphic(T1[R1].Right, T2[R2].Right);	//查询右结点
	if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) &&
		((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
		//根结点左边的子结点相等，
		//不需要交换左右节点
		return (Isomorphic(T1[R1].Left, T2[R2].Left) &&
				Isomorphic(T1[R1].Right, T2[R2].Right));
	else
		//需要交换节点
		return (Isomorphic(T1[R1].Left, T2[R2].Right) &&
				Isomorphic(T1[R1].Right, T2[R2].Left));
}
int main()
{
	Tree R1, R2;

	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

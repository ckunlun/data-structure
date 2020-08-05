//存在问题：Print函数中L1和L2最后无法正常输出NULL
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */  
                    // L1和L2最后无法正常输出NULL

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    List* L = NULL;
   // List* LL1, *LL2;//指针数组
    List lTemp;
    int iCnt = 0, iInd = 0;
   // LL1 = &L1;
    //LL2 = &L2;
    lTemp = L1;
    for (; L1; L1=L1->Next)
    {
        iCnt++;
    }
    L1 = lTemp;
    lTemp = L2;
    for (; L2; L2=L2->Next)
    {
        iCnt++;
    }
    L2 = lTemp;
    if ((L = (List*)malloc(sizeof(struct Node) * iCnt)) == NULL)
    {
        printf("申请内存失败");
        exit(0);
    }
    for (int i = 0; i < iCnt; i++)
    {
        if ((L[i] = (List)malloc(sizeof(struct Node))) == NULL)
        {
            printf("申请内存失败");
            exit(0);
        }
    }
    while (L1 && L2)
    {
        if (L1->Data < L2->Data)
        {

                L[iInd]->Data = L1->Data;
                if (iInd + 1 < iCnt)
                {
                    L[iInd]->Next = L[iInd+1];
                }
                else
                {
                    L[iInd]->Next = NULL;
                }
                lTemp = L1;
                L1 = L1->Next;
                free(lTemp);
                lTemp = NULL;
                iInd++;

        }
        else
        {
            while (L2 && L1->Data >= L2->Data)
            {

                
                    L[iInd]->Data = L2->Data;
                    if (iInd + 1 < iCnt)
                    {
                        L[iInd]->Next = L[1+iInd];
                    }
                    else
                    {
                        L[iInd]->Next = NULL;
                    }
                    lTemp = L2;
                    L2 = L2->Next;
                    free(lTemp);
                    lTemp = NULL;
                    iInd++;

            }
            if (L2)
            {

                
                    L[iInd]->Data = L1->Data;
                    if (iInd + 1 < iCnt)
                    {
                        L[iInd]->Next = L[1+iInd];
                    }
                    else
                    {
                        L[iInd]->Next = NULL;
                    }
                    lTemp = L1;
                    L1 = L1->Next;
                    free(lTemp);
                    lTemp = NULL;
                    iInd++;

            }
            else
            {
                while(L2)
                {

                    
                        L[iInd]->Data = L2->Data;
                        if (iInd + 1 < iCnt)
                        {
                            L[iInd]->Next = L[1+iInd];
                        }
                        else
                        {
                            L[iInd]->Next = NULL;
                        }
                        lTemp = L2;
                        L2 = L2->Next;
                        free(lTemp);
                        lTemp = NULL;
                        iInd++;

                }
            }
        }
    }
    while(L2)
    {

            L[iInd]->Data = L2->Data;
            if (iInd + 1 < iCnt)
            {
                L[iInd]->Next = L[1+iInd];
            }
            else
            {
                L[iInd]->Next = NULL;
            }

            lTemp = L2;
            L2 = L2->Next;
            free(lTemp);
            lTemp = NULL;
            iInd++;

    }
    while (L1)
    {

        L[iInd]->Data = L1->Data;
        if (iInd + 1 < iCnt)
        {
            L[iInd]->Next = L[1 + iInd];
        }
        else
        {
            L[iInd]->Next = NULL;
        }

        lTemp = L1;
        L1 = L1->Next;
        free(lTemp);
        lTemp = NULL;
        iInd++;

    }
    //Print(*L);
    free(L1);
   // *LL1 = NULL;
    free(L2);
   // *LL2 = NULL;
    //free(lTemp);

    return *L;
}

List Read() /* 细节在此不表 */
{
    int iCnt;
    int iNum;
    scanf("%d", &iCnt);
    List* L = NULL;
    if ((L = (List*)malloc(sizeof(struct Node) * iCnt)) == NULL)
    {
        printf("申请内存失败");
        exit(0);
    }
    for (int i = 0; i < iCnt; i++)
    {
        if ((L[i] = (List)malloc(sizeof(struct Node))) == NULL)
        {
            printf("申请内存失败");
            exit(0);
        }
    }
    for (int i = 0; i < iCnt; i++)
    {
        scanf("%d", &iNum);

        L[i]->Data = iNum;
        if (i + 1 < iCnt)
        {
            L[i]->Next = L[i + 1];
        }
        else
        {
            L[i]->Next = NULL;
        }
    }       
    return *L;
}

void Print(List L)
{
    if (L->Data!= -572662307)//此处有问题
    {
        for (; L; L = L->Next)
        {
            printf("%d ", L->Data);
        }
    }
    else
    {
        printf("NULL");
    }
    printf("\n");
        
}
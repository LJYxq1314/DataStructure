#include "doubleCircleLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHEDCKOUT(ptr)          \
        do                      \
        {                       \
            if(ptr == NULL)     \
            {                   \
                exit(0);        \
            }                   \
        } while (0);            

        


/* 初始化 */
int doubleCircleLinkListInit(DoubleCircleLinkList **pList)
{
    int ret = 0;

    DoubleCircleLinkList *pDClist = (DoubleCircleLinkList *)malloc(sizeof(DoubleCircleLinkList) * 1);
    if (!(pDClist))
    {
        return -1;
    }
    memset(pDClist, 0, sizeof(DoubleCircleLinkList));

    pDClist->head = (Node *)malloc(sizeof(Node) * 1);
    if(!(pDClist->head))
    {
        return -1;
    }
    memset(pDClist->head, 0, sizeof(Node));

    pDClist->tail = (Node *)malloc(sizeof(Node) * 1);
    if(!(pDClist->tail))
    {
        return -1;
    }
    memset(pDClist->tail, 0, sizeof(Node));

    pDClist->head->data = 0;
    pDClist->head->next = NULL;
    pDClist->tail->next = NULL;
    pDClist->listSize = 0;
    
    *pList = pDClist;
    
    return ret;
}

/* 创造一个新节点 */
static Node * createNode(ELEMENTTYPE inData)
{
    Node * newNode = (Node *)malloc(sizeof(Node) * 1);
    if (newNode == NULL)
    {
        printf("CreateNode malloc error!\n");
        return NULL;
    }
    memset(newNode, 0, sizeof(Node));

    newNode->data = inData;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

/* 头插 */
int doubleCircleLinkListInsertHead(DoubleCircleLinkList *pList, ELEMENTTYPE inData)
{
    return doubleCircleLinkListInsertByPos(pList, inData, 0);
}

/* 尾插 */
int DoubleCircleLinkListInsertTail(DoubleCircleLinkList *pList, ELEMENTTYPE inData)
{
    return doubleCircleLinkListInsertByPos(pList, inData, pList->listSize);
}

/* 按位插 */
int doubleCircleLinkListInsertByPos(DoubleCircleLinkList *pList, ELEMENTTYPE inData, int pos)
{
    int ret = 0;
    
    if(!(pList))
    {
        return -1;
    }

    Node *insertNode = createNode(inData);

    if(pos < 0 || pos > pList->listSize)
    {
        printf("linkListInsertByPos invalid position\n");
    }

    Node * pTravel = pList->head;

    /* !!! 数据备份 */
    int tempos = pos;

    /* 优化todo... */
    while (pos != 0)
    {
        pTravel = pTravel->next;
        pos--;
    }

    if(pList->listSize == 0)
    {
        insertNode->next = pTravel;
        insertNode->prev = pTravel;
        pTravel->next = insertNode;
        pTravel->prev = insertNode;
    }
    else if(tempos == pList->listSize)
    {
        insertNode->next = pTravel->next;
        insertNode->prev = pTravel;
        pTravel->next = insertNode;

    }
    else
    {
        insertNode->next = pTravel->next;       
        pTravel->next->prev = insertNode;       
        insertNode->prev = pTravel;             
        pTravel->next = insertNode;  
    }
    pList->listSize++;

    return ret;
}


/* 按位删 */
int doubleCircleLinkListDelByPos(DoubleCircleLinkList *pList, Node *pListNode, int pos)
{
    int ret = 0;

    /* 判空 */

    /* 越界或者链表不存在 */
    if(pos < 0 || pos >= pList->listSize || pList->listSize == 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
    {
        Node *pTravel = pList->head;
        while (pos != 0)
        {
            pTravel = pTravel->next;
            pos--;
        }

        Node * storageNode = pTravel->next;
        pTravel->next = storageNode->next;
        free(storageNode);
        pList->listSize--;
    }

    
    return ret;
}

/* 按位改值 */
int doubleCircleLinkListChangeByPos(DoubleCircleLinkList *pList, Node *pListNode, int pos, ELEMENTTYPE inData)
{
    /* 判空 */
    int ret = 0;

     if(pos < 0 || pos >= pList->listSize || pList->listSize == 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
    {
        Node *pTravel = pList->head;
        while (pos != 0)
        {
            pTravel = pTravel->next;
            pos--;
        }
        
        pTravel->next->data = inData;
    }

    return ret;
}

/* 按值查找：返回个数 */
int doubleCircleLinkListFindByVal(DoubleCircleLinkList *pList, Node *pListNode, ELEMENTTYPE inVal)
{
    /* 判空 */
    int ret;

    Node *pTravel = pList->head;
    int count = 0;
    while (pTravel->next != NULL)
    {
        pTravel = pTravel->next;
        if(pTravel->data == inVal)
        {
            count++;
        }

    }
    printf("count=%d\n", count);

    return ret;
}

/* 遍历链表 */
int doubleCircleLinkListTravel(DoubleCircleLinkList *pList,Node *pListNode)
{
    int ret = 0;

    /* 判空 */
    
    Node *pTravel = pList->head;
    while (pTravel->next != pList->head)
    {
        pTravel = pTravel->next;
        printf("Data=%d ",pTravel->data);
    }
    printf("\n");
    return ret;
}

/* 释放链表 */
int doubleCircleLinkListFree(DoubleCircleLinkList *pList, Node *pListNode)
{
    /* 判空 */
    
    Node *pTravel = pList->head->next;
    while (pTravel != NULL)
    {
        free(pList->head);
        pList->head = pTravel;
        pTravel = pTravel->next;
    }
    free(pList->head);
    return 0;
}

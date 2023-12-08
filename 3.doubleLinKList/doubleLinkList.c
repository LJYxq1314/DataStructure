#include "doubleLinkList.h"
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

        

int doubleLinkListInit(DoubleLinkList *pList)
{
    int ret = 0;
    pList = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    if(!(pList))
    {
        return -1;
    }
    memset(pList, 0, sizeof(DoubleLinkList));


    pList->head = (Node *)malloc(sizeof(Node) * 1);
    if(!(pList->head))
    {
        return -1;
    }
    memset(pList->head, 0, sizeof(Node));

    pList->head->next = NULL;//0*0
    pList->listSize = 0;
    pList->tail = pList->head ;
    
    return ret;
}

/* 二级指针初始化 */
int doubleLinkListTwoPtrInit(DoubleLinkList **pList)
{
    int ret = 0;

    DoubleLinkList *pDlist = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    if (!(pDlist))
    {
        return -1;
    }
    memset(pDlist, 0, sizeof(DoubleLinkList));

    pDlist->head = (Node *)malloc(sizeof(Node) * 1);
    if(!(pDlist->head))
    {
        return -1;
    }
    memset(pDlist->head, 0, sizeof(Node));

    pDlist->head->data = 0;
    pDlist->head->next = NULL;
    pDlist->tail = pDlist->head;

    *pList = pDlist;
    

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
int doubleLinkListInsertHead(DoubleLinkList *pList, ELEMENTTYPE inData)
{
    return doubleLinkListInsertByPos(pList, inData, 0);
}

/* 尾插 */
int doubleLinkListInsertTail(DoubleLinkList *pList, ELEMENTTYPE inData)
{
    return doubleLinkListInsertByPos(pList, inData, pList->listSize);
}

/* 按位插 */
int doubleLinkListInsertByPos(DoubleLinkList *pList, ELEMENTTYPE inData, int pos)
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
        insertNode->next = pTravel->next;
        insertNode->prev = pTravel;
        pTravel->next = insertNode;
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
int doubleLinkListDelByPos(DoubleLinkList *pList, Node *pListNode, int pos)
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
int doubleLinkListChangeByPos(DoubleLinkList *pList, Node *pListNode, int pos, ELEMENTTYPE inData)
{
    /* 判空 */
    int ret = 0;

     if(pos < 0 || pos >= pList->listSize || pList->listSize == 0)
    {
        printf("Invalid position");
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
int doubleLinkListFindByVal(DoubleLinkList *pList, Node *pListNode, ELEMENTTYPE inVal)
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
int doubleLinkListTravel(DoubleLinkList *pList,Node *pListNode)
{
    int ret = 0;

    /* 判空 */
    
    Node *pTravel = pList->head;
    while (pTravel->next != NULL)
    {
        pTravel = pTravel->next;
        printf("Data=%d ",pTravel->data);
    }
    printf("\n");
    return ret;
}

/* 释放链表 */
int doubleLinkListFree(DoubleLinkList *pList, Node *pListNode)
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

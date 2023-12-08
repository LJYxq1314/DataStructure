#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define CHECK_PTR       /
//         do              /
//         {               /
//             if(!)        /
//         } while (0);    /
        

int linkListInit(LinkList *pLinkList)
{
    int ret = 0;
    pLinkList->head = (ListNode *)malloc(sizeof(ListNode) * 1);
    if(!(pLinkList->head))
    {
        return -1;
    }
    
    pLinkList->head->next = NULL;
    pLinkList->head->data = 0;
    pLinkList->listSize = 0;
    
    return ret;
}

/* 创造一个新节点 */
static ListNode * createNode(ELEMENTTYPE inData)
{
    ListNode * newNode = (ListNode *)malloc(sizeof(ListNode) * 1);
    if (newNode == NULL)
    {
        printf("CreateNode malloc error!\n");
        return NULL;
    }
    memset(newNode, 0, sizeof(ListNode));
    
    newNode->data = inData;
    newNode->next = NULL;
    return newNode;
}

/* 尾部插值 */
int linkListInsertTail(ListNode *pListNode, LinkList *pLinkList, ELEMENTTYPE inData)
{
    int ret = 0;
    /* 判空 */
    ListNode *insertNode = createNode(inData);
    if(pLinkList->head == NULL)
    {
        pListNode = pLinkList->head;
    }
    else
    {
        ListNode *pPtravel = pLinkList->head;
        while(pPtravel->next != NULL)
        {
            pPtravel = pPtravel->next;
        }
        pPtravel->next = insertNode;
    }
    pLinkList->listSize++;

    return ret;
}

int linkListInsertByPos(ListNode *pListNode, LinkList *pLinkList, ELEMENTTYPE inData, int pos)
{
    int ret = 0;

    if(pos < 0 || pos > pLinkList->listSize)
    {
        printf("linkListInsertByPos invalid position\n");
    }

    ListNode * pTravel = pLinkList->head;
    while (pos != 0)
    {
        pTravel = pTravel->next;
        pos--;
    }
    ListNode *insertNode = createNode(inData);
    insertNode->next = pTravel->next;
    pTravel->next = insertNode;

    pLinkList->listSize++;
    return ret;
}

/* 按位删值 */
int linkListDelByPos(ListNode *pListNode, LinkList *pLinkList ,int pos)
{
    int ret = 0;

    /* 判空 */

    if(pos < 0 || pos > pLinkList->listSize)
    {
        printf("Invalid position");
        return -1;
    }
    else
    {
        ListNode *pTravel = pLinkList->head;
        while (pos != 0)
        {
            pTravel = pTravel->next;
            pos--;
        }

        ListNode * storageNode = pTravel->next;
        pTravel->next = storageNode->next;
        free(storageNode);
    }

    
    return ret;
}

/* 按位改值 */
int linkListChangeByPos(ListNode *pListNode, LinkList *pLinkList, int pos, ELEMENTTYPE inData)
{
    /* 判空 */
    int ret = 0;

     if(pos < 0 || pos > pLinkList->listSize)
    {
        printf("Invalid position");
        return -1;
    }
    else
    {
        ListNode *pTravel = pLinkList->head;
        while (pos != 0)
        {
            pTravel = pTravel->next;
            pos--;
        }
        
        pTravel->next->data = inData;
    }

    return ret;
}

/* 按值查找 */
int linkListFindByVal(ListNode *pListNode, LinkList *pLinkList, ELEMENTTYPE inVal)
{
    /* 判空 */
    int ret;

    ListNode *pTravel = pLinkList->head;
    int count = 0;
    while (pTravel->next != NULL)
    {
        pTravel = pTravel->next;
        if(pTravel->data == inVal)
        {
            count++;
        }

    }
    printf("count=%d\n",count);
    
    return ret;
}

int linkListTravel(ListNode *pListNode, LinkList *pLinkList)
{
    int ret = 0;

    /* 判空 */
    
    ListNode *pTravel = pLinkList->head;
    while (pTravel->next != NULL)
    {
        pTravel = pTravel->next;
        printf("Data=%d ",pTravel->data);
    }
    printf("\n");
    return ret;
}

int linkListFree(ListNode *pListNode, LinkList *pLinkList)
{
    /* 判空 */
    
    ListNode *pTravel = pLinkList->head->next;
    while (pTravel != NULL)
    {
        free(pLinkList->head);
        pLinkList->head = pTravel;
        pTravel = pTravel->next;
    }
    free(pLinkList->head);
    return 0;
}

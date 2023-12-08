#ifndef __DOUBLECIRCLELINKLIST_H_
#define __DOUBLECIRCLELINKLIST_H_

typedef int ELEMENTTYPE;

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    ELEMENTTYPE data;
}Node;

typedef struct DoubleCircleLinkList
{
    Node *head;
    Node *tail;
    int listSize;
    
}DoubleCircleLinkList;


/* 初始化 */
int doubleCircleLinkListInit(DoubleCircleLinkList **pList);

/* 头插 */
int doubleCircleLinkListInsertHead(DoubleCircleLinkList *pList, ELEMENTTYPE inData);

/* 尾插 */
int DoubleCircleLinkListInsertTail(DoubleCircleLinkList *pList, ELEMENTTYPE inData);

/* 按位插 */
int doubleCircleLinkListInsertByPos(DoubleCircleLinkList *pList, ELEMENTTYPE inData, int pos);

/* 按位删 */
int doubleCircleLinkListDelByPos(DoubleCircleLinkList *pList, Node *pListNode, int pos);

/* 按位改值 */
int doubleCircleLinkListChangeByPos(DoubleCircleLinkList *pList, Node *pListNode, int pos, ELEMENTTYPE inData);

/* 按值查找 */
int doubleCircleLinkListFindByVal(DoubleCircleLinkList *pList, Node *pListNode, ELEMENTTYPE inVal);

/* 遍历链表 */
int doubleCircleLinkListTravel(DoubleCircleLinkList *pList, Node *pListNode);

/* 释放链表 */
int doubleCircleLinkListFree(DoubleCircleLinkList *pList, Node *pListNode);


#endif
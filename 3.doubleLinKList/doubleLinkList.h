#ifndef __DOUBLELINKLIST_H_
#define __DOUBLELINKLIST_H_

typedef int ELEMENTTYPE;

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    ELEMENTTYPE data;
}Node;

typedef struct DoubleLinkList
{
    Node *head;
    Node *tail;
    int listSize;
    
}DoubleLinkList;

/* 初始化*/
int doubleLinkListInit(DoubleLinkList *pList);
/* 二级指针初始化 */
int doubleLinkListTwoPtrInit(DoubleLinkList **pList);

/* 头插 */
int doubleLinkListInsertHead(DoubleLinkList *pList, ELEMENTTYPE inData);

/* 尾插 */
int doubleLinkListInsertTail(DoubleLinkList *pList, ELEMENTTYPE inData);

/* 按位插 */
int doubleLinkListInsertByPos(DoubleLinkList *pList, ELEMENTTYPE inData, int pos);

/* 按位删 */
int doubleLinkListDelByPos(DoubleLinkList *pList, Node *pListNode, int pos);

/* 按位改值 */
int doubleLinkListChangeByPos(DoubleLinkList *pList, Node *pListNode, int pos, ELEMENTTYPE inData);

/* 按值查找 */
int doubleLinkListFindByVal(DoubleLinkList *pList, Node *pListNode, ELEMENTTYPE inVal);

/* 遍历链表 */
int doubleLinkListTravel(DoubleLinkList *pList, Node *pListNode);

/* 释放链表 */
int doubleLinkListFree(DoubleLinkList *pList, Node *pListNode);


#endif
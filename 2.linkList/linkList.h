#ifndef __LINKLIST_H_
#define __LINKLIST_H_



typedef  int ELEMENTTYPE;

typedef struct ListNode
{
    struct ListNode *next;             //节点的next指针
    ELEMENTTYPE data;                  //节点的数据
    

}ListNode;

typedef struct LinkList
{
    int listSize;                    //链表长度
    ListNode * head;                 //链表头节点
}LinkList;

/* 初始化链表 */
int linkListInit(LinkList *pLinkList);

/* 插入 */
/* 尾插 */
int linkListInsertTail(ListNode *pListNode, LinkList *pLinkList, ELEMENTTYPE inData);

int linkListInsertByPos(ListNode *pListNode, LinkList *pLinkList, ELEMENTTYPE inData, int pos);


/* 删除 */
/* 按位删值 */
int linkListDelByPos(ListNode *pListNode, LinkList *pLinkList ,int pos);

/* 改值 */
/* 按位改值 */
int linkListChangeByPos(ListNode *pListNode, LinkList *pLinkList, int pos, ELEMENTTYPE inData);

/* 查值 */
/* 按值查找 */
int linkListFindByVal(ListNode *pListNode, LinkList *pLinkList, ELEMENTTYPE inVal);

/* 遍历 */
int linkListTravel(ListNode *pListNode, LinkList *pLinkList);

/* 释放 */
int linkListFree(ListNode *pListNode, LinkList *pLinkList);

#endif
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

/* 按位插值 */

/* 按位删除 */

/* 按值查找 */

/* */



#endif
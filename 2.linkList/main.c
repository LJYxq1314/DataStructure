#include <stdio.h>

#include "linkList.h"

#define TEST_NUM 20


int main(int argc, char const *argv[])
{
    
    LinkList linkList;
    ListNode listNode;

    /* 初始化 */
    linkListInit(&linkList);

    /* 增 */
    for(int idx = 0; idx <TEST_NUM; idx++)
    {
        linkListInsertTail(&listNode, &linkList, idx);
    }
    
    linkListTravel(&listNode, &linkList);

    /* 删 */
    linkListDelByPos(&listNode, &linkList, 17);
    linkListTravel(&listNode, &linkList);

    linkListDelByPos(&listNode, &linkList, 17);
    linkListTravel(&listNode, &linkList);

    /* 改 */
    linkListChangeByPos(&listNode, &linkList, 17, 22);
    linkListTravel(&listNode, &linkList);

    linkListInsertByPos(&listNode, &linkList, 0, 0);
    linkListInsertByPos(&listNode, &linkList, 33, 19);
    linkListTravel(&listNode, &linkList);

    linkListInsertByPos(&listNode, &linkList, 44, 19);
    linkListTravel(&listNode, &linkList);

    for(int idx = 0; idx < TEST_NUM; idx++)
    {
      linkListInsertByPos(&listNode, &linkList, idx + 10, 0);
    }
    linkListTravel(&listNode, &linkList);


    linkListFindByVal(&listNode, &linkList, 10);
    
    linkListFree(&listNode, &linkList);


    return 0;
}

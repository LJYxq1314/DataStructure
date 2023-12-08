#include <stdio.h>

#include "linkList.h"

#define TEST_NUM 3


int main(int argc, char const *argv[])
{
    
    LinkList linkList;
    ListNode listNode;

    /* 初始化 */
    linkListInit(&linkList);

    /* 增 */
    for(int idx = 1; idx < TEST_NUM; idx++)
    {
        linkListInsertTail(&listNode, &linkList, idx);
    }
    printf("\n111111->size:%d\n", linkList.listSize);

    linkListInsertByPos(&listNode,  &linkList , 99, 0);
    printf("\n222222->size:%d\n", linkList.listSize);

    linkListInsertByPos(&listNode,  &linkList , 999, 1);
    printf("\n3333333->size:%d\n", linkList.listSize);


    
    linkListTravel(&listNode, &linkList);

    printf("\nsize:%d\n", linkList.listSize);


    // /* 删 */
    // linkListDelByPos(&listNode, &linkList, 17);
    // linkListTravel(&listNode, &linkList);

    // linkListDelByPos(&listNode, &linkList, 17);
    // linkListTravel(&listNode, &linkList);

    // /* 改 */
    // linkListChangeByPos(&listNode, &linkList, 17, 22);
    // linkListTravel(&listNode, &linkList);

    // linkListInsertByPos(&listNode, &linkList, 0, 0);
    // linkListInsertByPos(&listNode, &linkList, 33, 19);
    // linkListTravel(&listNode, &linkList);

    // linkListInsertByPos(&listNode, &linkList, 44, 19);
    // linkListTravel(&listNode, &linkList);

    // for(int idx = 0; idx < TEST_NUM; idx++)
    // {
    //   linkListInsertByPos(&listNode, &linkList, idx + 10, 0);
    // }
    // linkListTravel(&listNode, &linkList);


    // linkListFindByVal(&listNode, &linkList, 10);
    
    linkListFree(&listNode, &linkList);


    return 0;
}

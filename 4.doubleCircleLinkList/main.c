#include "doubleCircleLinkList.h"
#include <stdio.h>

#define TEST_NUM 10

int main(int argc, char const *argv[])
{
    DoubleCircleLinkList *dCList;
    Node dCNode;

    doubleCircleLinkListInit(&dCList);

    for(int idx = 0; idx < TEST_NUM; idx++)
    {
        doubleCircleLinkListInsertByPos(dCList, idx, 0);
        doubleCircleLinkListInsertByPos(dCList, idx, dCList->listSize);
    }
    doubleCircleLinkListTravel(dCList, &dCNode);

    for(int idx = 0; idx < TEST_NUM; idx++)
    {
        doubleCircleLinkListDelByPos(dCList, &dCNode, 0 );
    }
    doubleCircleLinkListTravel(dCList, &dCNode);

    printf("dCList->listSize = %d\n",dCList->listSize);

    doubleCircleLinkListChangeByPos(dCList, &dCNode, 0, 11);
    doubleCircleLinkListTravel(dCList, &dCNode);

    doubleCircleLinkListChangeByPos(dCList, &dCNode, dCList->listSize - 1, 99);
    doubleCircleLinkListTravel(dCList, &dCNode);

    return 0;
}


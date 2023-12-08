#include "doubleLinkList.h"
#include <stdio.h>

#define TEST_NUM 10

int main(int argc, char const *argv[])
{
    DoubleLinkList *dList = NULL;
    Node *dNode;
    doubleLinkListTwoPtrInit(&dList);
    
    for(int idx = 0; idx < TEST_NUM; idx++)
    {
        doubleLinkListInsertByPos(dList, idx, 0);
    }



    doubleLinkListDelByPos(dList, dNode, 0);
    // doubleLinkListDelByPos(dList, dNode, dList->listSize);
    doubleLinkListChangeByPos(dList, dNode, 0, 11);
    doubleLinkListTravel(dList, dNode);

    printf("dList->listSize = %d\n",dList->listSize);
    doubleLinkListTravel(dList, dNode);

    doubleLinkListChangeByPos(dList, dNode, dList->listSize - 1, 99);
    doubleLinkListTravel(dList, dNode);


    doubleLinkListFindByVal(dList, dNode, 99);

    doubleLinkListTravel(dList, dNode);
    doubleLinkListFree(dList, dNode);

    return 0;
}

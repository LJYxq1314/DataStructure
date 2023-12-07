#include "dynamicArray.h"

#define INSERT_NUM 10

int main(int argc, char const *argv[])
{
    DynamicArray array;
    initArray(&array);

    for(int idx = 0 ;idx < INSERT_NUM ;idx++)
    {
        insertData(&array, idx + 1);
        printf("array[%d] = %d\n",idx,array.dyArray[idx]);
    }
    insertData(&array,111);
    insertData(&array,112);
    insertData(&array,112);
    insertData(&array,111);
    insertData(&array,112);
    insertData(&array,112);
    insertData(&array,111);
    insertData(&array,112);
    insertData(&array,112);
    insertData(&array,111);
    insertData(&array,112);
    insertData(&array,112);
    insertData(&array,111);
    insertData(&array,112);
    insertData(&array,112);
    insertData(&array,111);
    insertData(&array,112);
    insertData(&array,112);
    
    deleteData(&array,5);


    for(int idx = 0 ;idx < INSERT_NUM + 15 ;idx++)
    {
        printf("array[%d] = %d\n",idx,array.dyArray[idx]);
    }

    printf("m_len:%d  m_capacity:%d\n",*(&array.m_len),*(&array.m_capacity));
    freeDynamicArray(&array);





    // for(int idx = 0 ;idx < INSERT_NUM ;idx++)
    // {
    //     insertData(&array,idx + 1);
    //     printf("array[%d] = %d\n",idx,array.dp[idx]);
    // }
    // insertData(&array,0);
    // insertData(&array,1);
    // insertData(&array,2);
    // insertData(&array,3);
    // insertData(&array,4);
    // insertData(&array,5);
    // insertData(&array,6);
    // insertData(&array,7);
    // insertData(&array,8);
    // insertData(&array,9);
    // insertData(&array,10);
    // insertData(&array,11);

    // printf("%d %d",array.m_capacity,array.m_len);

    // printf("%d\n",array.dp[0]);
    // printf("%d\n",array.dp[1]);
    // printf("%d\n",array.dp[2]);
    // printf("%d\n",array.dp[3]);
    // printf("%d\n",array.dp[4]);
    // printf("%d\n",array.dp[5]);
    // printf("%d\n",array.dp[6]);
    // printf("%d\n",array.dp[7]);
    // printf("%d\n",array.dp[8]);
    // printf("%d\n",array.dp[9]);
    // printf("%d\n",array.dp[10]);
    

    return 0;
}

#include "dynamicArray.h"

#define false 0
#define true 1

/* todo... */
// #define MALLOC_ERROR 
#define ENARGE_CAPACITY  10
#define ARRAY_CAPACITY   10


int initArray(DynamicArray *array)
{
    // if(array == NULL)
    // {
    //     return false;
    // }

    int ret = true;

    array->dyArray = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * ENARGE_CAPACITY);
    if(array->dyArray == NULL)
    {
        printf("InitArray malloc error\n");
    }
    /* 清除脏数据 */
    memset(array->dyArray, 0, sizeof(ELEMENTTYPE) * ENARGE_CAPACITY);  /* core dump 1 */

    array->m_len = 0;
    array->m_capacity = ARRAY_CAPACITY;
    

    /* todo... */
    return true;
}

static int reallocArray(DynamicArray *array)
{
    /* todo... 判空？*/
    if(array == NULL || array->dyArray == NULL)
    {
        printf("reallocArray error");
        return false;
    }

    /* 备份数据 */
    ELEMENTTYPE * tempArray = array->dyArray;
    
    array->dyArray = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * ARRAY_CAPACITY * 2);
    if(array->dyArray == NULL)
    {
        printf("ReallocArray malloc error\n");
        return false;
    }
    memset(array->dyArray ,0 ,sizeof(ELEMENTTYPE) * ARRAY_CAPACITY * 2);
    
    /* 拷贝原数组的值 */
    for (int idx = 0; idx < array->m_len; idx++)
    {
        array->dyArray[idx] = tempArray[idx];
    }
    
    array->m_capacity = array->m_capacity * 2;
    free(tempArray); 
    /* todo ...*/
       
    return true;    
}

int insertData(DynamicArray *array, ELEMENTTYPE data)
{
    // if(array == NULL)
    // {
    //     return false;
    // } 

    /* 当数组当前长度达到最大容量时 */
    if(array->m_len == array->m_capacity)
    {
        if(reallocArray(array) == false)
        {
            printf("Can not realloc more space\n");
            return false;
        }
    }

    array->dyArray[array->m_len] = data; /* core dump 2 */
    array->m_len++;
    return true;
}


int deleteData(DynamicArray *array ,int index)
{
    if(index < 0 || index > array->m_len)
    {
        printf("invalid index\n");
    }

    for(int idx = index ;idx < array->m_len ;idx++)
    {
        array->dyArray[idx] = array->dyArray[idx + 1];
    }

    array->m_len--;
    return true;
}

int changeData(DynamicArray *array ,int index ,ELEMENTTYPE data)
{
    if(index < 0 || index > array->m_len)
    {
        printf("invalid index\n");
    }

    array->dyArray[index] = data;

    return true;
}

// int selectData(DynamicArray *array ,int index ,ELEMENTTYPE data)
// {
//     if(index < 0 || index > array->m_len)
//     {
//         printf("invalid index\n");
//     }

//     int select = array->dp[index];

//     return true;
// }

void freeDynamicArray(DynamicArray *array)
{
    if(array->dyArray != NULL)
    {
        free(array->dyArray);
        array->dyArray = NULL;
    }
}

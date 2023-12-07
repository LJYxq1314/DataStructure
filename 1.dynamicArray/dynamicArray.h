#ifndef __DYNAMICARRAY_H_
#define __DYNAMICARRAY_H_

#define ELEMENTTYPE int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 动态数组结构体 */
typedef struct DynamicArray
{
    ELEMENTTYPE *dyArray;     //指针
    int m_capacity;      //数组的容量
    int m_len;           //数组的长度
    /* todo... */
}DynamicArray;

/* 初始化数组*/
int initArray(DynamicArray *array);
int insertData(DynamicArray *array ,ELEMENTTYPE data); 
int deleteData(DynamicArray *array ,int index);
int changeData(DynamicArray *array ,int index ,ELEMENTTYPE data);
// int selectData(DynamicArray *array ,int index ,ELEMENTTYPE data);
void freeDynamicArray(DynamicArray *array);



#endif
//
//  PermuteSort.c
//  LocalAlgrithm
//
//  Created by  潘易  on 16/3/20.
//  Copyright (c) 2016年 xinlan. All rights reserved.
//

#include "Tool.h"

struct Tag_Node
{
    int property;
    int value;
};

typedef struct Tag_Node Node;

//产生一个优先级数组 重新排序给定数列  得到一个随机排列的数组
int permuteBySorting(int *data,int len);

//基于交换的重新排序数组算法
int randomInPlace(int *data,int len);

int main()
{
    int data[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int len = sizeof(data)/sizeof(data[0]);
    
    srand((unsigned)time(NULL));
    
    showArray(data, len);
    randomInPlace(data, len);
    
    printf("After resort:\n");
    showArray(data, len);
    
    return 0;
}//end main

void testPermuteArray()
{
    int data[]={1,2,3,4,5,6,7,8,9,10,11,100};
    int len = sizeof(data)/sizeof(data[0]);
    
    showArray(data, len);
    permuteBySorting(data, len);
    
    printf("After resort:\n");
    showArray(data, len);
}

//产生一个优先级数组 重新排序给定数列  得到一个随机排列的数组
int permuteBySorting(int *data,int len)
{
    Node *proArray = (Node *)malloc(sizeof(Node));
    if(proArray == NULL)
        return ERROR;
    
    //int node arrray value;
    int max = len * len * len;
    for(int i = 0; i < len; i++)
    {
        proArray[i].value = data[i];
        proArray[i].property = randomInt(0, max);
    }//end for i
    
    //sort propery array
    // insert sort 插入排序策略
    for(int i = 1; i < len;i++)
    {
        Node value = proArray[i];
        int j = i - 1;
        for(; j >= 0; j--)
        {
            if(value.property > proArray[j].property)
            {
                break;
            }else{
                proArray[j + 1] = proArray[j];
            }//end if
        }//end for j
        proArray[j + 1] = value;
    }//end for i
    
    //reset data value
    for(int i = 0;i < len; i++)
    {
        data[i] = proArray[i].value;
    }//end for i
    
    free(proArray);
    proArray = NULL;
    
    return OK;
}

//基于交换的重新排序数组算法
int randomInPlace(int *data,int len)
{
    for(int i = 0;i < len; i++)
    {
        //swap element i with rnd(i ~ len - 1)
        int swapIndex = randomInt(i, len - 1);
        int temp = data[i];
        data[i] = data[swapIndex];
        data[swapIndex] = temp;
    }//end for i
    return OK;
}



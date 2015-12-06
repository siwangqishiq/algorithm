//
//  MergeSort.c
//  Algorithm
//
//  Created by  潘易  on 15/12/6.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//  归并排序算法实现
// 

#include <stdio.h>

#include "Tool.h"

void merge(int *data,int p,int q,int r);//合并两有序数组

int mergeSort(int *data,int start,int end);//归并排序

int main()
{
    int data[] = {9,3,1,0,4,10,2,8,7};
    int len = sizeof(data)/sizeof(data[0]);
    showArray(data,len);
    mergeSort(data,0,len -1);
    showArray(data,len);
    return 0;
}

//归并排序
// param -data 数组地址
// param -start  开始位置
// param -end 结束位置
int mergeSort(int *data,int start,int end)
{
    if(end > start)
    {
        int mid = (start + end) / 2;
        mergeSort(data,start,mid);
        mergeSort(data,mid+1,end);
        
        merge(data, start, mid, end);
    }
    return 0;
}

//两有序数组的合并
// param -  mid 中间位置
void merge(int *data,int start,int mid,int end)
{
    //printf("start = %d  mid = %d   end = %d\n",start,mid,end);
    int leftArrayLen = mid - start + 1;
    int rightArrayLen = end - mid;
    
    //malloc memory
    int *pLeftData = (int *)malloc(leftArrayLen * sizeof(int));
    int *pRightData = (int *)malloc(rightArrayLen * sizeof(int));
    
    //拷贝数据
    for(int i=0;i<leftArrayLen;i++)
    {
        pLeftData[i] = data[start +i];
    }//end for i
    
    for(int i=0;i<rightArrayLen;i++)
    {
        pRightData[i] = data[mid + 1 +i];
    }//end for j
    
    //合并
    int i = 0,j = 0,index = start;
    while(i<leftArrayLen && j<rightArrayLen)
    {
        if(pLeftData[i] < pRightData[j])
        {
            data[index++] = pLeftData[i++];
        }else{
            data[index++] = pRightData[j++];
        }//end if
    }//end while
    
    while(i < leftArrayLen)
    {
        data[index++] = pLeftData[i++];
    }//end while for i
    while(j < rightArrayLen)
    {
        data[index++] = pRightData[j++];
    }//end while for i
    
    
    //free memory
    free(pLeftData);
    free(pRightData);
    
    //showArray(data,end - start +1);
}









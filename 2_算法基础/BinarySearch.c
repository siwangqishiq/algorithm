//
//  BinarySearch.c
//  Algorithm
//
//  Created by  潘易  on 15/12/6.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//

#include <stdio.h>
#include "Tool.h"

int binarySearchs(int *data,int start,int end,int key);

int main_binarySearch()
{
    int data[] = {1,2,3,4,5,6,7,8,9,10,11,12,14,15,19,20,23,28,29,30};
    int len = sizeof(data)/sizeof(data[0]);
    
    //int data[] = {1};
    //int len = sizeof(data)/sizeof(data[0]);
    
    for(int i=0;i<len;i++)
    {
        int ret = binarySearchs(data, 0,len - 1,data[i]);
        printf("%d \n",ret);
    }

    int ret = binarySearchs(data, 0,len - 1,13);
    printf("%d \n",ret);
    
    printf("%d \n",binarySearchs(data, 0,len - 1,17));
    
    return 0;
}

// 二分查找法
// return 返回找到元素的索引值
// 没有找到 返回-1
int binarySearchs(int *data,int start,int end,int key)
{
    int left = start;
    int right = end;
    
    while(left <= right)
    {
        //printf("left = %d   right = %d\n",left,right);
        if(left == right)
        {
            return left;
        }//end if
        
        if(right - left ==1)
        {
            if(data[left] == key)
                return left;
            if(data[right] == key)
                return right;
            
            return -1;
        }//end if
        
        int mid = (left + right) / 2;
        
        if( key > data[mid])
        {
            left = mid;
        }else if(key < data[mid]){
            right = mid;
        }else{
            return mid;
        }//end if
    }// end
    
    return -1;
}


//
//  Tool.c
//  Algorithm
//
//  Created by  潘易  on 15/12/6.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//

#include "Tool.h"

//print array data
void showArray(int *data,int len)
{
    int i = 0;
    for(;i < len; i++)
    {
        printf("%d   ",data[i]);
    }//end for i
    printf("\n");
}

int binarySearch(int *data,int start,int end,int key)
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

int randomInt(int min,int max)
{
	return (rand() % (max - min + 1)) + min;
}


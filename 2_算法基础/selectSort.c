//
//  2_2_2.c
//  Algorithm
//
//  Created by  潘易  on 15/12/3.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//  选择排序
//

#include <stdio.h>

#define MAX_VALUE    999999

//print array data
void showArray(int *data,int len)
{
    int i = 0;
    for(;i < len; i++)
    {
        printf("%d    ",data[i]);
    }//end for i
    printf("\n");
}

//选择排序
int selectSort(int *data,int len)
{
    int i,j;
    int bound = len - 1;
    for(i = 0;i < bound;i++)
    {
        int min = data[i];
        int index = i;
        for(j = i;j < len;j++)
        {
            if(min > data[j])
            {
                min = data[j];
                index = j;
            }//end if
        }//end for j
        
        //swap the index and i data  value
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }//end for i
    
    return 0;
}

int main()
{
    int data[] = {9,3,1,0,4,10,2,8,7};
    int len = sizeof(data)/sizeof(data[0]);
    showArray(data,len);
    selectSort(data,len);
    showArray(data,len);
    
    return 0;
}
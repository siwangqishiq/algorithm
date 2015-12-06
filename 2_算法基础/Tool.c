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
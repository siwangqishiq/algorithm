//
//  2.c
//  Algorithm
//
//  Created by  潘易  on 15/12/2.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//

//输入 n个序列 v的数值
//输出下标i  使得v= a[i] 或者 当v不在a中时 v为特殊nil
#include <stdio.h>

#define nil -1

int handleData(int *data,int len,int value)
{
    int ret = -1;
    int i;
    for(i = 0;i < len; i++)
    {
        if(value == data[i])
        {
            ret = i;
        }
    }//end for i
    if(ret != -1)
    {
        printf("i = %d\n",ret);
    }else{
        printf("v为特殊值nil \n");
    }//end if
    
    
    return 1;
}

int main()
{
    int data[]={10,9,8,7,6,5,4,3,2,1,0};
    int len = sizeof(data)/sizeof(int);
    
    handleData(data,len,13);
    return 0;
}

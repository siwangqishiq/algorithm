//
//  2.c
//  Algorithm
//
//  Created by  潘易  on 15/12/2.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//  两个n位的二进制整数相加

#include <stdio.h>
#include <stdlib.h>

int addNum(int *a,int *b,int n,int *out,int out_len)
{
    int i;
    int prior = 0;
    for(i = n-1;i >= 0; i--)
    {
        int result = a[i]+b[i]+prior;
        if(result >= 2)//产生进位
        {
            result -=2;
            prior = 1;
        }else{
            prior = 0;
        }
        out[i+1] = result;
    }//end for i
    out[0] = prior;
    
    return 1;
}

void printNum(int *data,const int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        printf("%d",data[i]);
    }//end for i
    printf("\n");
}

void printNum2(int *data,const int n)
{
    int i;
    printf(" ");
    for(i = 0;i < n;i++)
    {
        printf("%d",data[i]);
    }//end for i
    printf("\n");
}

int main()
{
    //int a[]={1,0,1,0,1,0,0};
    //int b[]={1,0,1,0,1,0,0};
    int a[]={1,1};
    int b[]={1,1};
    int len = sizeof(a)/sizeof(int);
    int retLen = len+1;
    int *c = (int *)malloc(retLen * sizeof(int));
    
    addNum(a,b,len,c,retLen);
    printNum2(a,len);
    printNum2(b,len);
    printNum(c,retLen);
    free(c);
    
    return 0;
}

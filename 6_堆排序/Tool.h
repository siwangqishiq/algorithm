//
//  Tool.h
//  Algorithm
//
//  Created by  潘易  on 15/12/6.
//  Copyright (c) 2015年 xinlan. All rights reserved.
//

#ifndef __Algorithm__Tool__
#define __Algorithm__Tool__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK          0
#define ERROR   -1

//print array data
void showArray(int *data,int len);

int binarySearch(int *data,int start,int end,int key);

//取得[a,b]的随机整数
//调用之前需调用  srand((unsigned)time(NULL)); 初始化
int randomInt(int min,int max);

#endif /* defined(__Algorithm__Tool__) */

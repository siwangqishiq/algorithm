//综合排序.c
//对数组排序 数组长度>k时  使用归并排序
// 长度<=k时   使用插入排序

#include <stdio.h>
#include "Tool.h"

void multipleSort(int *data,int start,int end,int limit);
void insertSort(int *data,int start,int end);
void mergeSort(int *data,int start,int end);
void merge(int *data,int start,int mid,int end);

int main()
{
	//int data[] = {9,3,1,0,4,10,2,8,7};
	int data[] = {4,3,5,1,2,6,8,7,11,10,9,14,9,3,1,0,4,10,2,8,7,12,29,24,23,17,19,18,15};
    int len = sizeof(data)/sizeof(data[0]);
    showArray(data,len);
    //insertSort(data,0,len-1);
	//mergeSort(data,0,len-1);
	multipleSort(data,0,len -1, 2);
    showArray(data,len);
	return 0;
}

//综合排序
//当数组长度>limit时  使用归并排序分治数组
//当数组长度<=limit时  使用插入排序排序数组
void multipleSort(int *data,int start,int end,int limit)
{
	int len = end - start + 1;
	//printf("len = %d  start = %d  end = %d 排序前\n",len,start,end);
	if(len <= limit )
	{
		insertSort(data, start, end);
	}else{//归并排序
		int mid = (start + end)/2;
		multipleSort(data, start, mid, limit);
		multipleSort(data, mid+1, end, limit);
		merge(data, start, mid, end);
	}//end if
	//printf("len = %d  start = %d  end = %d 排序end---\n",len,start,end);
}

//插入排序
void insertSort(int *data,int start,int end)
{
	int i = start +1;
	for( ; i <= end ; i++)
	{
		int insertValue = data[i];
		int p = i - 1;
		while(p >= start && insertValue < data[p])
		{
			data[p+1] = data[p];
			p--;
		}//end while p
		data[p+1] = insertValue;
	}//end for i
}

//归并排序
void mergeSort(int *data,int start,int end)
{
	if(end > start)
	{
		int mid = (start + end)/2;
		mergeSort(data,start,mid);
		mergeSort(data,mid+1,end);
		merge(data,start,mid,end);
	}
}

//合并两有序数组
void merge(int *data,int start,int mid,int end)
{
	int leftLen = mid - start + 1;
	int rightLen = end - mid;
	int i,j;
	int index = start;

	int *pLeft = (int *)malloc(leftLen * sizeof(int));
	int *pRight = (int *)malloc(rightLen * sizeof(int));
	
	for(i = 0;i < leftLen ; i++)
	{
		pLeft[i] = data[start + i];
	}//end for i
	
	for(i = 0;i < rightLen ; i++)
	{
		pRight[i] = data[mid+ 1 + i];
	}//end for i

	i = j = 0;
	while(i < leftLen && j < rightLen)
	{
		if(pLeft[i] < pRight[j])
		{
			data[index++] = pLeft[i++];
		}else{
			data[index++] = pRight[j++];
		}//end if
	}//end for i and j

	while(i < leftLen)
	{
		data[index++] = pLeft[i++];
	}//end while i
	while(j < rightLen)
	{
		data[index++] = pRight[j++];
	}

	free(pLeft);
	free(pRight);
}



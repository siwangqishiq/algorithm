//逆序数计算
//计算一个给定数组data  中所有逆序数对的数量
#include <stdio.h>
#include <stdlib.h>

int computeInverseNumber(int *data,int start,int end);
int mergeInverseNumber(int *data,int start,int end);
int merge(int *data,int start,int mid,int end);

int main()
{
	int data[]={5,3,4,21,2};
	int len = sizeof(data)/sizeof(data[0]);
	
	int inverseNum = computeInverseNumber(data,0,len-1);
	printf("data inverse number = %d \n",inverseNum);

	inverseNum = mergeInverseNumber(data,0,len-1);
	printf("data inverse number = %d \n",inverseNum);

	return 0;
}

//计算data 从start~end范围内的逆序数对
// 传统穷举法 求逆序数数量
// param    data
// param   start
// param  end
// return     the number of data's inverse number
int computeInverseNumber(int *data,int start,int end)
{
	int i,j;
	int num = 0;
	for( i = start;i < end ;i++)
	{
		int value = data[i];
		for(j =i + 1;j<=end;j++)
		{
			if(value > data[j]) num++;
		 }//end for j
	}//end for i

	return num;
}

//计算data 从start~end范围内的逆序数对
// 归并法求逆序数
// param    data
// param   start
// param  end
// return     the number of data's inverse number
int mergeInverseNumber(int *data,int start,int end)
{
	if(end - start <1)
		return 0;

	//printf("%d  %d\n",start,end);
	int mid = (start + end) / 2;
	int leftNum = mergeInverseNumber(data,start,mid);
	int rightNum = mergeInverseNumber(data,mid+1,end);
	int mergeNum = merge(data,start,mid,end);

	return leftNum + rightNum +mergeNum;
}

//合并两有序数组 
//return 两有序数组合并后的逆序数
int merge(int *data,int start,int mid,int end)
{
	int num = 0;
	
	int leftLen = mid - start + 1;
	int rightLen = end - mid;

	int *pLeft = (int *)malloc(leftLen * sizeof(int));
	int *pRight = (int *)malloc(rightLen * sizeof(int));
	
	int i,j;
	int index = start;

	for(i = 0; i < leftLen ; i++)
	{
		pLeft[i] = data[start+i];
	}//end for i
	for(i = 0; i < rightLen ; i++)
	{
		pRight[i] = data[mid + 1 +i];
	}//end for i
	
	i = 0;
	j = 0;
	while(i < leftLen && j < rightLen)
	{
		if(pLeft[i] < pRight[j])
		{	
			data[index++] = pLeft[i++];
		}else{
			num = num + leftLen - i;
			data[index++] = pRight[j++];
		}//end if
	}//end while

	while(i < leftLen)
	{
		data[index++] = pLeft[i++];
	}
		
	while(j < rightLen)
	{
		data[index++] = pRight[j++];
	}		

	free(pLeft);
	free(pRight);

	return num;
}

// 
// 寻找数组中最大子序列
//
// 线性时间算法  O(n) 
#include <stdio.h>

#define MIN_VALUE  -999999999

void printResult(int *data,int left,int right,int maxSubarray);
int findMaxSubarray(int *data,int start,int end,int *pLeft,int *pRight);

int main()
{
	int data[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int len = sizeof(data)/sizeof(data[0]);
	int left = 0,right = 0;
	int maxSubArray = findMaxSubarray(data,0,len - 1,&left,&right);
	
	printResult(data,left,right,maxSubArray);

	return 0;
}

//求得最大子序列  
//时间复杂度O(N)
int findMaxSubarray(int *data,int start,int end,int *pLeft,int *pRight)
{
	int maxSubarray = MIN_VALUE;
	int left,right;
	int i,j;
	int sum = 0;
	left = right = start;

	for(i = start; i <= end; i++)
	{
		sum = 0;
		for(j = i; j >= start;j--)
		{
			sum += data[j];
			if(sum > maxSubarray)
			{
				maxSubarray = sum;
				left = j;
				right = i;
			}//end if
		}//end for j
	}//end for i
	
	*pLeft = left;
	*pRight = right;
	return maxSubarray;
}

void printResult(int *data,int left,int right,int maxSubarray)
{
	int i;
	printf("max sub array is: ");
	for(i = left; i<=right;i++)
	{
		printf("%d  ",data[i]);
	}//end for i
	printf("\n");
	printf("max sub array value is: %d\n",maxSubarray);
}

int addAll(int *data,int start,int end)
{
	int sum = 0;
	int i;
	for(i = start; i<= end;i++)
	{
		sum += data[i];
	}//end for i
	return sum;
}



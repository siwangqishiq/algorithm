// 
// 寻找数组中最大子序列

// findMaxSubarrayOrigin 穷举法发现  O(n*n)
// findMaxSubarrayDivideConquer  分治法 世界复杂度O(nlgn)
#include <stdio.h>

#define MIN_VALUE  -999999999

void findMaxSubarrayOrigin(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight);
void printResult(int *data,int left,int right,int maxSubarray);
int addAll(int *data,int start,int end);



int main()
{
	int data[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int len = sizeof(data)/sizeof(data[0]);
	
	int maxValue = 0;
	int left,right;
	findMaxSubarrayOrigin(data,0,len -1, &maxValue,&left,&right);
	printResult(data,left,right,maxValue);

	return 0;
}

//穷举
void findMaxSubarrayOrigin(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight)
{
	int i , j;
	int left,right;
	int max = MIN_VALUE;

	for(i = start; i <= end ; i++)
	{
		for(j = i;j <= end;j++)
		{
			int sum = addAll(data,i,j);					
			if(sum > max)
			{
				max = sum;
				left = i;
				right = j;
			}	
		}//end for j
		
	}//end for i

	*pMaxSubarray = max;
	*pLeft = left;
	*pRight = right;
}

//分治法  求得最大子数组
void findMaxSubarrayDivideConquer(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight)
{
	
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



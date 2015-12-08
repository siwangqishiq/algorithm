// ц╟ещеепР.c

#include <stdio.h>
#include "Tool.h"

void bubbleSort(int *data,int start,int end);

int main()
{
	int data[] = {4,3,5,1,2,6,8,7,11,10,9,14,9,3,1,0,4,10,2,8,7,12,29,24,23,17,19,18,15};
    int len = sizeof(data)/sizeof(data[0]);
    showArray(data,len);
	bubbleSort(data,0,len - 1);
    showArray(data,len);
	return 0;
}

//ц╟ещеепР
void bubbleSort(int *data,int start,int end)
{
	int i,j;
	for(i = start; i<=end; i++)
	{
		for( j = end;j>i;j--)
		{
			if(data[j] < data[j - 1])
			{
				int temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
			}
		}//end for j
	}//end for i
}
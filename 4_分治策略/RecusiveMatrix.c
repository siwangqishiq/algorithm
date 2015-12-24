#include <stdio.h>

#define N  100

typedef struct _MatrixN
{
	int rows;
	int **data;
} MatrixN;

void handle(int (*data)[3],int m)
{
	int i,j;
	for(i = 0;i < m; i++)
	{
		for( j = 0;j < m ;j++)
		{
			printf("%5d",data[i][j]);
		}//end for j
		printf("\n");
	}//end for i
}

int add(int a,int b)
{
	return a + b;
}

int sub(int a,int b)
{
	return a - b;
}

typedef struct 
{
	int a;
	int b;
	int (*handle)(int a,int b);
} Operation;

void doMatrix(int *a)
{
	printf("%5d",a[1][2]);
}

int main()
{
	//int a[3][3] = {1,2,3,4,5,6,7,8,9};
	//handle(a,3);
	int a[]={1,2,3,4,5,6,7,8,9};
	
	printf("%d \n",*a);
	printf("%d \n",*(&a));

	Operation oper;
	oper.a = 11;
	oper.b = 13;
	oper.handle = add;
	
	int result = oper.handle(12,15);
	printf("%d\n",result);
	doMatrix(a);
	return 0;
}
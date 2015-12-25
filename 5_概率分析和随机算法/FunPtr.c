#include <stdio.h>

typedef int (*add)(int *data,int num);

typedef struct Tag_Node
{
	char *name;
	add func;
} Node;

int myAdd(int *data,int len)
{
	int ret = 0;
	int i;
	for(i = 0;i < len ; i++)
	{
		ret += data[i];
	}
	return ret;
}

int main()
{
	int data[] = {1,2,3,4,5,6};
	int len = sizeof(data) / sizeof(data[0]);
	Node node;
	node.func = myAdd; 
	printf("%d \n", node.func(data, len) );	
	return 0;
}//end main
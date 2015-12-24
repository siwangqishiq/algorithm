// 生成随机数
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 
//要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a; 
//要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1; 
//通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。 
//要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。 
//要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。

//取得[a,b]的随机整数
//调用之前需调用  srand((unsigned)time(NULL)); 初始化
int randomInt(int min,int max)
{
	return (rand() % (max - min + 1)) + min;
}

int main()
{
	int i;
	for(i = 0; i < 10 ; i++)
	{
		printf("%d \n",randomInt(1,100));
	}//end for i
	return 0;
}
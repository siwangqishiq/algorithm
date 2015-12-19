#include <stdio.h>
#include <string.h>

#define    TURE    1
#define    FALSE  -1

void naiveStringMatcher(const char *str,const char *p);
int stringMatch(const char *left,const char *right,int len);

int main()
{
	char *str = "aabcdabcdeabcabc";
	char *p = "abc";
	naiveStringMatcher(str,p);
	
	return 0;
}

//朴素字符串匹配算法
// param   str 搜索串
// param   p 模式串
// 显示偏移值
void naiveStringMatcher(const char *str,const char *p)
{
	int strLen = strlen(str);
	int pLen = strlen(p);
	int i;
	int end = strLen - pLen + 1;
	for(i = 0;i < end; i++)
	{
		if(stringMatch(str+i,p,pLen) == TURE)
		{
			printf("s = %d \n",i);
		}
	}//end for i
}

//检验left right len长度字符是否相等
//
int stringMatch(const char *left,const char *right,int len)
{
	int i;
	for(i = 0;i < len; i++)
	{
		if(left[i] != right[i]) 
			return FALSE;
	}//end for i
	return TURE;
}

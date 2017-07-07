#include <stdio.h>
#include <string.h>

int indexOf(char *t,int len,char *p,int pLen);

int main(int argc,char *argv[]){
	char str[]="abcbcaaaaooopqqwwww111222333";
	int str_size = sizeof(str) / sizeof(char);
	//str_size = strlen(str);
	char sub[] = "222333";
	int sub_size = sizeof(sub) / sizeof(char) - 1;
	//sub_size = strlen(sub);

	printf("%d , %d \n",str_size,sub_size);

	int p = indexOf(str,str_size,sub,sub_size);
	printf("index = %d \n",p);

	return 0;
}

int indexOf(char *t,int len,char *p,int pLen) {
	if(!pLen)
		return -1;

	int max = len - pLen;

	if(max < 0)
		return -1;

	for(int i = 0;i <= max; i++){
		int j = 0;
		int index = 0;
		while(index < pLen && t[i + index] == p[index]){
			index++;
		}//end while
		if(index == pLen)
			return i;
	}//end for i

	return -1;
}

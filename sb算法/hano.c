#include <stdio.h>


void hano(int n,char a,char b,char c){
	if(n == 1){
		printf("move %d from %c to %c \n",n, a, b);
	}else{
		hano(n - 1 , a , c , b);
		printf("move %d from %c to %c \n",n, a, b);
		hano(n - 1 , c, b,  a);
	}
}


int main(int argc, char *argv[]){
	hano(4,'a','b','c');
	return 0;
}
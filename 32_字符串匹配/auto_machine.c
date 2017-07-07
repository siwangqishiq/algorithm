//基于有限状态自动机的字符串匹配算法
#include <stdio.h>
#include <string.h>

const char CHAR_SET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
							'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
							'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
						

const int CHAR_SET_SIZE = sizeof(CHAR_SET) / sizeof(char);

#define MAX_SIZE 1024

struct _AutoMachine
{
	char status[MAX_SIZE];//自动机状态集
	char statusSize;//自动机状态数量
	char cur;//自动机当前状态
	char accept;//可接受状态，当前自动机只存在一种可接受状态
	char transFuc[MAX_SIZE][MAX_SIZE];//二维矩阵存贮的状态转移函数
};

typedef struct _AutoMachine AutoMachine;


int createAutoMachine(char *pattern,int size,AutoMachine *mac);

int autoMachineIndexOf(char *t,int len,char *p,int pLen);

int autoMachineReadChar(AutoMachine *mac,char c);//自动机读入字符  返回状态

int charToIndex(char c);

void debugMac(AutoMachine *mac){
	printf("auto machine status list:\n");

	for(int i = 0; i< mac->statusSize ;i++){
		printf("status_%d\n",mac->status[i]);
	}
	printf("accept status_%d\n",mac->accept);
	
	for(int i = 0;i<CHAR_SET_SIZE;i++){
		char ch = CHAR_SET[i];
		printf("%c index = %d \n",ch ,charToIndex(ch));
	}
}

int main(int argc,char *argv[]){
	char str[]="abcbcaaaaooopqqwwww111222333";
	int str_size = sizeof(str) / sizeof(char);
	char sub[] = "w111222";
	int sub_size = sizeof(sub) / sizeof(char) - 1;
	
	printf("%d , %d \n",str_size,sub_size);
	
	int p = autoMachineIndexOf(str,str_size,sub,sub_size);
	printf("index = %d \n",p);
	
	return 0;
}

//根据匹配串 构建自动机
int createAutoMachine(char *pattern,int size,AutoMachine *mac){
	//printf(" mac size = %d \n",sizeof(*mac));
	mac->statusSize = size + 1;
	for( int i = 0 ;i < mac->statusSize ; i++){
		mac->status[i] = i;
	}//end for i
	mac->cur = 0;//初始状态
	mac->accept = size;//终止状态
	
	//构造状态转移函数
	memset(mac->transFuc,0,MAX_SIZE * MAX_SIZE);
	
	return -1;
}

int autoMachineReadChar(AutoMachine *mac,char c){
	mac->cur = mac->transFuc[mac->cur][charToIndex(c)];
	return mac->cur;
}

int autoMachineIndexOf(char *t,int len,char *p,int pLen) {
	if(!pLen)
		return -1;

	int max = len - pLen;

	if(max < 0)
		return -1;
	
	AutoMachine am;
	createAutoMachine(p,pLen,&am);
	debugMac(&am);
	
	for(int i = 0;i < len ;i++){
		if(autoMachineReadChar(&am,t[i]) == am.accept){
			return i - pLen;
		}//end if
	}//end for i
	
	return -1;
}

int charToIndex(char c){
	for(int i = 0; i < CHAR_SET_SIZE;i++){
		if(c == CHAR_SET[i])
			return i;
	}
	return CHAR_SET_SIZE;
}

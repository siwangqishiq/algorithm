#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize_str(char *data, int start , int data_len ,int count);

int main(int argc ,char *argv[]){
	char input[] = "    ToDAY is  a   very GOOD day   ";
	
	printf("%s \n" , input);
	normalize_str(input , 0 ,strlen(input) ,0);
	printf("%s \n" , input);
	return 0;
}

void normalize_str(char *data, int start , int data_len ,int count){	
	if(start >= data_len)
		return;
	
	char *p = data + start;
	int index= 0 ;
	int vob_start = 0;
	
	//找到第一个非空的字节
	while(*p == ' '){
		p++;
		vob_start++;
	}//end while
	//printf("index = %d   vob_start = %d \n" ,index , vob_start);
	int isfirst = 1;
	while(*p != ' ' && *p!='\0'){
		data[start + index] = (count%2==0 && isfirst)?toupper(data[start + vob_start +index]):
		tolower(data[start + vob_start +index]);
		
		data[start + vob_start +index] = ' ';
		index++;
		p++;
		isfirst = 0;
	}//end while
	
	//printf("index = %d  \n" ,  start + index  );
	normalize_str(data , start + index + 1, data_len, count + 1);
}


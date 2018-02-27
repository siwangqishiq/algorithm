#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize_str(char *data, int start , int data_len ,int count);

int main(int argc ,char *argv){
	char input[] = "    ToDAY is  a   very GOOD day   ";
	
	printf("%s \n" , input);
	normalize_str(input , 0 ,strlen(input) ,0);
	normalize_str(input , 5 ,strlen(input) ,1);
	printf("%s \n" , input);
	return 0;
}

void normalize_str(char *data, int start , int data_len ,int count){	
	if(start >= data_len)
		return;
	
	char *p = data + start;
	int index= start ;
	int vob_index = index;
	
	//找到第一个非空的字节
	while(*p == ' '){
		p++;
		vob_index++;
	}//end while
	printf("index = %d   %d \n" ,index , vob_index);
	while(*p != ' ' && *p!='\0'){
		data[start + index] = tolower(data[start + vob_index +index]);
		data[start + vob_index +index] = ' ';
		index++;
		p++;
	}//end while
}


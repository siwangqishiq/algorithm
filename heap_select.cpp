#include <iostream>
#include <random>

#include "data.h"

class MinHeap {
public:
	MaxHeap(int _size) : size(_size){
		pData = new int[size + 1];
		for(int i = 1 ; i <= size ;i++){
			
		}//end for i
	}
	
	~MinHeap(){
		delete pData;
		pData = nullptr;
	}
private:
		int size;
		int limit;
		int *pData;
};

int genRandomInt(int min , int max) {
	static std::random_device rd;
	
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
	
	return dis(gen);
}

std::string genDataCode(int dataCount) {
	std::string result = "int data[] = { ";
	for(int i = 0 ; i < dataCount ; i++) {
		std::string v = std::to_string(genRandomInt(0,100));
		if(i != 0){
			result += ", ";
		}
		result += v;
	}//end for i
	result += "};";
	return result;
}

int main(int argc , char *argv[]) {
		
	for(int i = 0 ; i< data_len;i++){
		std::cout << data[i] <<std::endl;
	}
	
	
	
	
	
	//cout << "Hello World" << endl;
	return 0;
}
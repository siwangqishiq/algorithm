#include <iostream>
#include <random>

class MaxHeap {
public:
	MaxHeap(int _size) : size(_size){
		pData = new int[size + 1];
		for(int i = 1 ; i <= size ;i++){
			
		}//end for i
	}
	
	~MaxHeap(){
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

int main(int argc , char *argv[]) {
		
	int data[] = {100,200,3,1,8,90,87,99,34,34,87,76,56,55,99,102 , 97, 98,7,73,34};
	int data_len = sizeof(data) / sizeof(int);
	
	std::random_device rd;
	
	
	//cout << "Hello World" << endl;
	return 0;
}
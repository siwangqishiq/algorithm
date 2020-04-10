#include <iostream>
#include <random>
#include <memory>
#include <vector>

#include "data.h"

//最小堆
class MinHeap {
public:
	MinHeap(int _capacity) : capacity(_capacity){
		pData = std::unique_ptr<int []>(new int[capacity + 1]);
		count = 0;
	}

	int push(int element) {
		if(isFull()){
			return -1;
		}

		int insertIndex = count + 1;
		
		pData[insertIndex] = element;
		count++;

		int index = insertIndex;

		//插入后的上浮操作
		while(index > 1){
			int curIndex = index;
			index = index / 2;
			if(index >= 1){
				if(element < pData[index]){ //todo swap
					int temp = pData[index];
					pData[index] = pData[curIndex];
					pData[curIndex] = temp;
				}
			}
		}//end while
		
		return 0;
	}

	int getTopValue(int *pTopValue){
		if(isEmpty()){
			return -1;
		}

		*pTopValue = pData[1];
		return 0;
	}
	
	int popTop(int *pTopValue){
		if(isEmpty()){
			return -1;
		}

		const int originTopVal = pData[1];
		if(pTopValue != nullptr){
			*pTopValue = originTopVal;
		}

		const int curCount = count;
		const int lastElementValue = pData[count];
		pData[1] = lastElementValue;
		
		int index = 1;
		while(index <= curCount){
			int leftChildIndex = 2*index;
			int rightChildIndex = 2*index + 1;

			if(leftChildIndex <= curCount && rightChildIndex <= curCount){//左右子树均为合法值
				int leftValue = pData[leftChildIndex];
				int rightValue = pData[rightChildIndex];

				if(leftValue < rightValue){//左子树更小
					if(pData[index] < leftValue){
						break;
					}else{
						int temp = pData[index];
						pData[index] = pData[leftChildIndex];
						pData[leftChildIndex] = temp;

						index = leftChildIndex;
					}
				}else{//右子树更小
					if(pData[index] < rightValue){
						break;
					}else{
						int temp = pData[index];
						pData[index] = pData[rightChildIndex];
						pData[rightChildIndex] = temp;

						index = rightChildIndex;
					}
				}
			}else if(leftChildIndex <= curCount && rightChildIndex > curCount){ //左子树有值 右子树没有
				int leftValue = pData[leftChildIndex];
				if(pData[index] > leftValue){
					pData[index] = leftValue;
					index = leftChildIndex;
				}else{
					break;
				}
			} else {
				break;
			}
		}//end while
		count--;
		return 0;
	}

	int popTopAndInsert(int *pTopValue , int newValue){
		if(isEmpty()){
			return -1;
		}

		popTop(pTopValue);
		push(newValue);
		return 0;
	}

	bool isEmpty() {
		return count==0;
	}

	bool isFull() {
		return count >= capacity;
	}
	
	void putData(std::vector<int> *result){
		for(int i = 1 ; i<=count ;i++){
			result->push_back(pData[i]);
		}//end for i
	}

	void print(){
		std::cout << "[ ";
		for(int i = 1; i<= count ;i++){
			std::cout << pData[i] << " ";
		}
		std::cout << "]" << std::endl;
	}

	~MinHeap(){
		std::cout << "free heap data"<< std::endl;
	}

private:
	int capacity;
	int count;
	std::unique_ptr<int []> pData;

};//end class


std::vector<int> selectMaxNumbers(int d[] , int d_size , int count) {
	std::vector<int> result;
	MinHeap heap(count);

	for(int i = 0; i < d_size; i++){
		int dataValue = d[i];

		if(!heap.isFull()){//堆未满 直接插入
			heap.push(dataValue);
		}else{//栈已满
			int heapTopValue = 0;
			heap.getTopValue(&heapTopValue);//去除的是当前堆中最小的元素
			if(heapTopValue < dataValue){
				heap.popTopAndInsert(nullptr , dataValue);
			}
		}
	}//end for i
	//heap.print();
	heap.putData(&result);

	return result;
}

int main(int argc , char *argv[]) {
	std::vector<int> result = selectMaxNumbers(data , data_len , 100);
	std::cout << result.size() <<std::endl;

	std::cout << "max number is [";
	for(auto v : result){
		std::cout << v << " ";
	}//end for each
	std::cout << "]"<<std::endl;

	return 0;
}
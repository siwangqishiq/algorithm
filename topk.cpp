
#include<iostream>
#include <memory>

class MaxHeap{
public:
    MaxHeap(int _initSize):capacity(_initSize) {
        curSize = 0;

        pData = std::unique_ptr<int[]>(new int[capacity + 1]);
        for(int i = 1 ; i <= capacity;i++){
            pData[i] = i; 
        }//end for i
    }  

    void display(){
        for(int i = 1;i <= capacity;i++){
            std::cout << pData[i] << std::endl;
        }
    } 

    ~MaxHeap(){
        
    }
private:
    int curSize;
    int capacity;
    std::unique_ptr<int[]> pData;
};


int main(int argc ,char **agrv) {
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    int dataSize = sizeof(data) / sizeof(int);

    MaxHeap heap(4);
    heap.display();

    //std::cout << "a = " << a <<std::endl;

    return 0;
}

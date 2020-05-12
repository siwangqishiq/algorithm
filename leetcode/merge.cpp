


// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <iostream>
#include <vector>

typedef std::vector<int> ZoneType;

void merge(std::vector<ZoneType> *pSet , ZoneType zone){
    if(pSet == nullptr)
        return;

    int left = zone[0];
    int right = zone[1];
    if(left > right)
        return;

    for(int i = 0 , len = pSet->size(); i < len ; i++){
        ZoneType iZone = pSet->at(i);
        if(i == 0){//首个元素
            if(left < iZone[0]){

            }else{
                    
            }
        }else if(i == len -1){ //末尾元素
           if(right )
        }else{
            
        }
    }//end for i
    pSet->push_back({left , right});
}

std::vector<ZoneType> mergeAll(std::vector<ZoneType> *pInputs){
    ZoneType s={1,2};

    std::vector<ZoneType> result;

    for(int i = 0 ; i < pInputs->size();i++){
        merge(&result , pInputs->at(i));
    }//end for i

    return result;
}

void testVectorInsert() {
    
    std::vector<int> list = {0,1,2,3,4,5,6,7};

    std::cout << "[ ";
    for(int &v : list){
        std::cout << v << " ";
    }//end for each
    std::cout<< "]" << std::endl;

    list.insert(std::end(list) - 1, 777);

    std::cout << "[ ";
    for(int &v : list){
        std::cout << v << " ";
    }//end for each
    std::cout<< "]" << std::endl;
}

int main(int argc , char **argv){
    std::vector<ZoneType> inputs = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<ZoneType> result = mergeAll(&inputs);

    std::cout << "[ ";
    for(ZoneType &v : result){
        std::cout << "{ " << v[0] << " , " << v[1] << " }";
    }//end for each
    std::cout<< " ]" << std::endl;

    return 0;
}
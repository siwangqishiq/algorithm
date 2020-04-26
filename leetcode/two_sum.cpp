#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        auto len = nums.size();

        if(len <= 1){
            return result;
        }

        bool isFound = false;
        for(int i = 0 ; i < len;i++){
            for(int j = i + 1; j < len ; j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);

                    isFound = true;
                    break;
                }//end for i
            }//end for j

            if(isFound){
                break;
            }
        }//end for i

        return result;
    }
};

int main(int argc , char *argv[]){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    Solution solution;
    std::vector<int> result = solution.twoSum(nums , target);
    std::cout << "result is ";
    for(auto v : result){
        std::cout << v << " " ;
    }//end for each
    std::cout << std::endl;

    return 0;
}


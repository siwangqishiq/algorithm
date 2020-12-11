/**
 * 
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
 * 
 * */


#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty())
        return 0;

    int result = INT_MIN;
    for(int i = 0 ; i < nums.size();i++){
        int sub  = 0;
        for(int j = i;j < nums.size() ; j++){
           sub += nums[j]; 
           if(result < sub){
               result = sub;
           }
        }//end for start
    }
    return result;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1, 100,-5,4 };
    int r = maxSubArray(nums);
    std::cout << "max sub array : " << r << std::endl;
    return 0;
}



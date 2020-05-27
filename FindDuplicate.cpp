/**
 * 
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3
说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n^2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        // for(int i = 0 , len = nums.size() ; i < len ; i++){
        //     for(int j = nums.size() - 1 ; j > i ;j--){
        //         if(nums[j] < nums[j - 1]){
        //             int tmp = nums[j];
        //             nums[j] = nums[ j - 1];
        //             nums[j - 1] = tmp;
        //         }
        //     }//end for j
        // }//end for i
        
        std::sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            cout << nums[i] << "   ";
        }//end for i
        cout << endl;

        int check = nums[0];
        for(int i = 1 ; i < nums.size();i++){
            if(check == nums[i]){
                return check;
            }else{
                check = nums[i];
            }
        }
        return check;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3,1,3,4,2};
    int result = s.findDuplicate(nums);
    cout << "result = " << result << endl;

    return 0;
}
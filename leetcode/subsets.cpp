/**
 * 
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */


#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &vec){
    cout << "[ ";
    for(int &it : vec){
        cout << it << " ";
    }//end for each
    cout << "]" << endl;
}

void addSubSets(vector<int>& nums ,int index ,vector<int> &prior, vector<vector<int>> &result){
    if(index >= nums.size())
        return;
    
    //no add
    addSubSets(nums , index + 1 , prior , result);

    //add
    int data = nums[index];
    vector<int> added = prior;
    added.push_back(data);
    result.push_back(added);
    addSubSets(nums , index + 1 , added , result);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> empty;

    result.push_back(empty);

    addSubSets(nums , 0 ,empty , result);
    return result;
}

int main(){
    vector<int> nums = {1 , 2, 3 , 4 , 5};
    vector<vector<int>> result = subsets(nums);

    for(vector<int> e: result){
        printVector(e);
    }
    return 0;
}
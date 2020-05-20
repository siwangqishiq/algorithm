/***
 * 
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays


思路-> 较大的集合 找出中位数 取出此中位数 

 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return 0;
    }
};

double simpleFindMedian(vector<int> &nums1 , vector<int> &nums2){
    vector<int> mergeVec;
    int indexA = 0;
    int indexB = 0;

    while(indexA < nums1.size() || indexB < nums2.size()){
        if(indexA < nums1.size() && indexB < nums2.size()){
            int aVal = nums1[indexA];
            int bVal = nums2[indexB];

            if(aVal < bVal){
                mergeVec.push_back(aVal);
                indexA++;
            }else{
                mergeVec.push_back(bVal);
                indexB++;
            }
        }else if(indexA >= nums1.size() && indexB < nums2.size()){
            mergeVec.push_back(nums2[indexB]);
            indexB++;
        }else if(indexA < nums1.size() && indexB >= nums2.size()){
            mergeVec.push_back(nums1[indexA]);
            indexA++;
        }
    }//end while

    cout << "[ ";
    for(int v : mergeVec){
        cout << v << " ";
    }
    cout << "]" << endl;

    if(mergeVec.size() % 2 == 0){
        
    }else{

    }
    return 0;
}

int main(){
    vector<int> nums1={1,3,5 , 9};
    vector<int> nums2 = {2,4,6,7 ,8};
    double r = simpleFindMedian(nums1 , nums2);
    cout << r << endl;
    return 0;
}

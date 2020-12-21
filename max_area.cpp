/**
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
 * 垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

 

示例 1：



输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
示例 3：

输入：height = [4,3,2,1,4]
输出：16
示例 4：

输入：height = [1,2,1]
输出：2
 

提示：

n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;

int maxArea2(vector<int>& height) {
    if(height.empty() || height.size() <= 1)
        return 0;

    int area = 0;
    for(int i = 0 ; i < height.size() ;i++){
        for(int j = i + 1; j < height.size() ;j++){
            int newArea = (j - i) * (height[i] <= height[j] ? height[i] : height[j]);
            if(newArea > area) {
                area = newArea;
            }
        }//end for j
    }//end for i

    return area;
}

int maxArea(vector<int>& height) {
    if(height.empty() || height.size() <= 1)
        return 0;

    int left = 0;
    int right = height.size() - 1;
    int area = 0;

    while(left < right){
        int curArea = (right - left) * min(height[left] , height[right]);
        if(curArea > area){
            area = curArea;
        }

        if(height[left] <= height[right]){
            left++;
        }else{
            right--;
        }
    }//end while

    return area;
}

int main(){
    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    int r1 = maxArea(h1);
    cout << r1 << endl;

    vector<int> h2 = {1, 1};
    int r2 = maxArea(h2);
    cout << r2 << endl;

    vector<int> h3 = {4,3,2,1,4};
    int r3 = maxArea(h3);
    cout << r3 << endl;

    vector<int> h4 = {1,2,1};
    int r4 = maxArea(h4);
    cout << r4 << endl;

    return 0;
}
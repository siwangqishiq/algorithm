/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

#include <iostream>
#include <string>

using namespace std;

struct Limit{
    int left;
    int right;
};

class Solution {
private:
    Limit findLongestPalindrome(const char *data , int left , int right){
        Limit result = {left , right};

        int len = right - left;
        if(len <= 0){
            result.left = result.right = left;
        }else if(len == 1){
            result.left = left;
            result.right = left + 1;
        }else {
            if(len % 2 == 0){//偶数个元素
                int mid = (left + right) / 2;

                Limit l_limit = findLongestPalindrome(data , left , mid);
                Limit r_limit = findLongestPalindrome(data , mid , right);
                int offset = 0;
                
                while(mid + offset < right && mid - 1 - offset >= left){
                    if(data[mid - 1 - offset] != data[mid + offset]){
                        break;
                    }
                    offset++;
                }//end mid
                //offset -= 1;

                result.left = mid - offset;
                result.right = mid + offset;

                int l_len = l_limit.right - l_limit.left;
                int r_len = r_limit.right - r_limit.left;
                int mid_len = result.right - result.left;

                cout << "left : " << l_limit.left << " , " << l_limit.right << endl;
                cout << "mid : " << result.left << " , " << result.right << endl;
                cout << "right : " << r_limit.left << " , " << r_limit.right << endl;

                if(mid_len > l_len && mid_len > r_len){
                    //is right
                }else if(l_len > mid_len && l_len > r_len){
                    result = l_limit;
                }else if(r_len > mid_len && r_len > l_len){
                    result = r_limit;
                }
            }else{ //奇数个元素
                int mid = (left + right) / 2;
                Limit l_limit = findLongestPalindrome(data , left , mid);
                Limit r_limit = findLongestPalindrome(data , mid +1 , right);

                int offset = 0;
                while(mid + offset < right && mid - offset >= left){
                    if(data[mid - offset] != data[mid + offset]){
                        break;
                    }
                    offset++;
                }//end mid
                offset -= 1;

                result.left = mid - offset;
                result.right = mid + offset;

                int l_len = l_limit.right - l_limit.left;
                int r_len = r_limit.right - r_limit.left;
                int mid_len = result.right - result.left;

                cout << "left : " << l_limit.left << " , " << l_limit.right << endl;
                cout << "mid : " << result.left << " , " << result.right << endl;
                cout << "right : " << r_limit.left << " , " << r_limit.right << endl;

                if(mid_len > l_len && mid_len > r_len){
                    //is right
                }else if(l_len > mid_len && l_len > r_len){
                    result = l_limit;
                }else if(r_len > mid_len && r_len > l_len){
                    result = r_limit;
                }
            }
        }

        return result;
    }

public:
    string longestPalindrome(string s) {
        string result="";
        int len = s.length();
        const char *data = s.c_str();

        Limit limit = findLongestPalindrome(data , 0 , len);
        cout << limit.left << "  " << limit.right << endl;
        result = string(data + limit.left , limit.right - limit.left);
        return result;
    }
};




bool isPalindrome(const char *s , int len){
    if(len == 0)
        return true;
    //const char *s = str.c_str();
    //int len = str.length();
    int mid = len / 2;
    for(int i = 0; i < mid ; i++){
        if(s[i] != s[len - i - 1]){
            return false;
        }
    }

    return true;
}

class Solution2 {
public:
    string longestPalindrome(string s) {
        string result="";
        
        int curMaxLength;
        int curIndex;

        int maxPalindromeLen = 0;
        const int len = s.length();
        const char *data = s.c_str();

        for(int i = 0 ; i < len ; i++){
            for(int j = i;j < len ; j++){
                int subStrLen = j - i + 1;

                // string subStr = string(data + i , subStrLen);
                // cout << subStr << endl;
                if(isPalindrome(data + i , subStrLen) && subStrLen > curMaxLength){
                    //result = string(data + i , subStrLen);
                    curMaxLength = subStrLen;
                    curIndex = i;
                }
            }
        }//end for i
        
        result = string(data + curIndex , curMaxLength);
        return result;
    }
};


//动态规划解法
class Solution3 {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return "";

        
        const char *data = s.c_str();
        const int len = s.length();
        
        int longest = 0;
        int longestIndex = -1;

        bool memo[len][len];// i-> j 的字串 是否是回文   
        for(int checkLen = 0;checkLen < len ;checkLen++){
            for(int i = 0;i< len -checkLen;i++){
                //check[i , i + checkLen]
                if(checkLen == 0){
                    memo[i][i + checkLen] = true;
                }else if(checkLen == 1){
                    memo[i][i + checkLen] = (data[i] == data[i + checkLen]);
                }else{
                    memo[i][i + checkLen] = (data[i] == data[i + checkLen]) && memo[i + 1][i + checkLen - 1];
                }

                if(memo[i][i + checkLen] && checkLen + 1 > longest){
                    longest = checkLen;
                    longestIndex = i;
                }
                string subStr = string(data +i , checkLen + 1);
                cout << "->" << subStr << " is " << memo[i][ i + checkLen] <<  endl;
            }//end for i
        }//end for checkLen

        if(longestIndex >= 0){
            return string(data + longestIndex , longest + 1);
        }
        return "";
    }
};


int main() {
    Solution3 s;
    
    string longestPalindrome = s.longestPalindrome("bab");
    cout << "longest result = " << longestPalindrome << endl;
    return 0;
}


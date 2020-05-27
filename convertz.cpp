/**
 * 
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
 * 
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string convert(string str , int rowNum) {
        if(str == "")
            return "";

        if(rowNum <= 1){
            return str;
        }

        int index = 0;

        const char *data = str.c_str();
        const int len = str.length();
        
        vector<vector<char>> result;
        int state = 0;// 1

        bool isContinue = false;

        while(index < len){
            if(state == 0 ){
                vector<char> normalVec(rowNum ,' ');
                int start = index;
                for(int i = start;i < start + rowNum ;i++){
                    normalVec[i - start] = data[index];
                    index++;
                    
                    if(index >= len){
                        isContinue = true;
                        break;
                    }

                    //cout << "i = " << i << " start + rowNum =" << (start + rowNum) << endl;
                }//end for i

                //cout << "index = " << index << endl;
                result.push_back(normalVec);
                state = 1;
            } else if(state == 1){
                int rowIndex = rowNum - 2;

                while(rowIndex > 0){
                    vector<char> colVec(rowNum , ' ');
                    colVec[rowIndex] = data[index];
                    result.push_back(colVec);

                    index++;
                    rowIndex--;

                    if(index >= len){
                        isContinue = true;
                        break;
                    }
                }//end while

                state = 0;
            }

            if(isContinue){
                break;
            }
        }//end while

        // for(vector<char> &v : result){
        //     cout << "[ ";
        //     for(char c : v){
        //         cout << c << " ";
        //     }
        //     cout << "]" << endl;
        // }//end for each

        string convertStr = "";
        char buf[len + 1];
        int count = 0 ;
        for(int i = 0 ; i < rowNum ; i++){
            for(vector<char> &vec : result){
                //cout << vec[i] << ",";
                if(vec[i] != ' '){
                    //convertStr += string(1 , vec[i]);
                    buf[count++] = vec[i];
                }
            }//end for each
            //cout << endl;
        }
        buf[len] = '\0';
        cout << "buf : " << buf << endl;
        return string(buf);
    }
};

int main() {
    Solution s;
    string result = s.convert("LEETCODEISHIRING" , 3);
    cout << "result : " << result << endl; 

    result = s.convert("LEETCODEISHIRING" , 4);
    cout << "result : " << result << endl; 

    // vector<char> vec(4, 'a');
    // vec[2] = 'A';
    // for(char c : vec){
    //     cout << c << " ";
    // }
    // cout << endl;
    return 0;
}
/**
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
**/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool isIPSpan(const char *s , int size , string &value){
    
    if(size <= 0 || strlen(s) == 0)
        return false;
    
    if(size == 1){
        value = string(s , size);
        return true;
    }else if(size <= 3){        
        if(*s == '0'){
            return false;
        }
        value = string(s , size);
        //cout <<"s = " << s <<" size = " << size << " value =" << value << endl;
        return stoi(value) <=255;
    }else{
        return false;
    }
}

void restore(vector<string> &result ,string prefix , const char *str ,int step){
    int len = strlen(str);

    int limit = len > 3?3:len;
    for(int size = 1 ; size <= limit ;size++){
        string value;
        if(isIPSpan(str , size , value)){
            //cout << value << endl;
            string nextPrefix = prefix.empty()?value:prefix + string(".") + value;
            if(step == 4){
                string lastString = string(str + size);
                //cout << "last = " << lastString <<" isEmpty = " << lastString.empty() << endl;
                if(lastString.empty()){
                    result.push_back(nextPrefix);
                }
            }else{
                restore(result , nextPrefix , str + size , step + 1);
            }   
        }
    }//end for i
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    const char *str = s.c_str();
    int len = s.length();

    restore(result , "" , str ,1);

    return result;
}


void showVec(vector<string> &strVec){
    for(string &s : strVec){
        cout << s << endl;
    }//end for each
}

int main(){
    vector<string> result = restoreIpAddresses("000");
    showVec(result);
    return 0;
}





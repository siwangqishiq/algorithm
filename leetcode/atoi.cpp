/**
 * 
 * 请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0 。

提示：

本题中的空白字符只包括空格字符 ' ' 。
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
 

示例 1:

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
*/

#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

const int STATUS_IDLE =1;
const int STATUS_EAT_NUMBER =2;

int myAtoi(std::string s) {
    if(s.empty())
        return 0;

    const char *p = s.c_str();

    int status = STATUS_IDLE;
    int flag = 1;

    bool endRead = false;
    vector<int> values;

    while(*p != '\0'){
        char ch = *p;
        switch(ch){
            case ' ':
                if(status == STATUS_EAT_NUMBER){
                    endRead = true;
                }
                break;
            case '-':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                    flag = -1;
                }else {
                    endRead = true;
                }
                break;
            case '+':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                    flag = 1;
                }else {
                    endRead = true;
                }
                break;
            case '0':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(0);
                break;
            case '1':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(1);
                break;
            case '2':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(2);
                break;
            case '3':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(3);
                break;
            case '4':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(4);
                break;
            case '5':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(5);
                break;
            case '6':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(6);
                break;
            case '7':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(7);
                break;
            case '8':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(8);
                break;
             case '9':
                if(status == STATUS_IDLE){
                    status = STATUS_EAT_NUMBER;
                }
                values.push_back(9);
                break;
            default:
                endRead = true;
            break;
        }//end switch

        if(endRead)
            break;
        p++;
    }//end while

    
    if(values.empty()){
        return 0;
    }

    long long result = 0;
    for(int i = 0 ; i < values.size() ;i++){
        cout << values[i] << " ";
        
        //long long priorValue = result;

        result *= 10;
        result += values[i];

        cout << "result = " << result << endl;

        if(flag > 0){
            if(result > INT32_MAX)
                return INT32_MAX;
        }else{
            if(-result < INT32_MIN)
                return INT32_MIN;
        }
        
    }//end for i
    cout << endl;
    return flag * result;
}

int main(){
    // cout << "INT32_MIN : " << INT32_MIN << endl;

    // cout << myAtoi("42") << endl;
    // cout << myAtoi("    -42") << endl;

    // cout << myAtoi("4193 with words") << endl;
    // cout << myAtoi("words and 987") << endl;

    //cout << myAtoi("-91283472332") << endl;
    cout << myAtoi("00000-42a1234") << endl;

    //"   +0 123"
    cout << myAtoi("   +0 123") << endl;
    return 0;
}
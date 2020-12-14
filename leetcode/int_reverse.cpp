/**
 * 
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
*/

#include <iostream>
#include <climits>

using namespace std;

int int_max =  INT32_MAX;
int int_min =  INT32_MIN;

long doReverse(unsigned long num){
    long reverse = 0;
    while(num != 0){
        unsigned long value = num % 10;
        
        reverse += value;
        
        if(reverse > int_max){
            return 0;
        }

        cout << "num : " << num << " value: " << value << " reverse :" << reverse << endl;

        num = num / 10;

        if(num == 0)
            break;

        reverse *= 10;
    }//end while

    return reverse;
}

int reverse(int x) {
    long xl = x;
    // if(xl <= int_min || xl > int_max){
    //     return 0;
    // }

    if(xl > 0){
        return doReverse(xl);
    }else if(xl < 0){
        return -1 * doReverse(-xl);
    }else{
        return 0;
    }
}


int main(){
    // cout << reverse(-123456) << endl; 

    // cout << reverse(123) << endl;
    // cout << reverse(-123) << endl;
    // cout << reverse(120) << endl;

    cout << "INT_MAX = " << int_max << endl;
    cout << "INT_MIN = " << int_min << endl;

    cout << reverse(-2147483412) << endl;

    return 0;
}
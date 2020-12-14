/**
 * 
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
 * 
 * 
 * */

#include <iostream>
#include <vector>


using namespace std;

// double myPow(double x, int n) {
//     double result = 1;

//     if(n == 0)
//         return 1;
//     else if(n > 0){
//         for(int i = 0 ; i < n ;i++){
//             result *= x;
//         }
//     }else{
//         for(int i = 0 ; i < -n ;i++){
//             result *= x;
//         }

//         result = 1.0 / result;
//     }

//     return result;
// }


// double power(double x, int n) {
    
//     if(n == 0){
//         return 1;
//     }
//     return x * power(x , n - 1);
// }

// double myPow(double x, int n){
//     if(n == 0)
//         return 1;
//     else if(n > 0){
//         return power(x , n);
//     }else{
//         return 1.0 / power(x , -n);
//     }
// }



double power(double x, unsigned long n) {
    if(n <= 1)
        return x;

    long i = 1; 
    double ret = x;

    while(i < n){
        long i2 = i << 1;
        if(i2 >= n){
            break;
        }

        i = i2;
        ret *= ret;

        //cout << "i = " << i << " result = " << ret << endl;
    }//end while
    
    // cout << "n = " << n << " i =" << i <<  " result = " << ret << endl;
    if(n == i){
        return ret;
    }else{
        return ret * power(x , n - i);
    }
}

double myPow(double x, int n){
    long ln = n;
    if(ln == 0)
        return 1;
    else if(ln > 0){
        return power(x , ln);
    }else{
        return 1.0 / power(x , -ln);
    }
}


int main(){
    cout << myPow(2 , 10) << endl;
    cout << myPow(2.1 , 3) << endl;
    cout << myPow(2.00000, -2) << endl;

    cout << myPow(1, -2147483648) << endl;

    return 0;
}
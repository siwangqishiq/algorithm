/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * */

#include <iostream>
#include <string>
#include <unordered_set>

void printSubStr(const char *data, int limitLeft , int limitRight){
    int index = limitLeft;
    while(index < limitRight){
        std::cout << data[index++];
    }
    std::cout << std::endl;
}

void findLongsetSubStringCrossMid(const char *data , int mid , int left , int right , int *pOffsetLeft , int *pOffsetRight){
    std::cout << "mid  = " << mid << " left = " << left << " right = " << right << std::endl;
    std::unordered_set<char> charSet;

    // std::pair<int , int> offset;
    // offset.first = mid;
    // offset.second = mid + 1;
    int offsetLimitLeft = mid;
    int offsetLimitRight = mid + 1;

    charSet.insert(data[mid]);

    bool leftLoop = true;
    bool rightLoop = true;
    while(leftLoop || rightLoop) {
        //read left 
        if(leftLoop && (offsetLimitLeft - 1) >= left){
            const char c = data[offsetLimitLeft - 1];

            //  std::cout <<"check " << c << " is in { ";
            // for(char c : charSet){
            //     std::cout << c << " ";
            // }
            // std::cout << " }" <<std::endl;

            if(charSet.find(c) == charSet.end()){
                charSet.insert(c);
                offsetLimitLeft -= 1;
            }else{
                leftLoop = false;
            }
        }else{
            leftLoop = false;
        }

        // read right
        if(rightLoop && offsetLimitRight < right){
            const char c = data[offsetLimitRight];
            
            // std::cout <<"check " << c << " is in2 { ";
            // for(char c : charSet){
            //     std::cout << c << " ";
            // }
            // std::cout << " }" <<std::endl;

            if(charSet.find(c) == charSet.end()){
                charSet.insert(c);
                offsetLimitRight += 1;
            }else{
                rightLoop = false;
            }
        }else{
            rightLoop = false;
        }
    }//end while

    //因为是左闭右开区间 所以右边要 +1 

    charSet.clear();
    charSet.insert(data[mid]);

    // std::pair<int , int> offsetRight;
    // offsetRight.first = mid;
    // offsetRight.second = mid + 1;
    int offsetLimitLeft2 = mid;
    int offsetLimitRight2 = mid + 1;

    leftLoop = true;
    rightLoop = true;
    while(leftLoop || rightLoop) {
        // read right
        if(rightLoop && offsetLimitRight2 < right){
            const char c = data[offsetLimitRight2];
            if(charSet.find(c) == charSet.end()){
                charSet.insert(c);
                offsetLimitRight2 += 1;
            }else{
                rightLoop = false;
            }
        }else{
            rightLoop = false;
        }

        //read left 
        if(leftLoop && offsetLimitLeft2 - 1 >= left){
            const char c = data[offsetLimitLeft2 - 1];
            if(charSet.find(c) == charSet.end()){
                charSet.insert(c);
                offsetLimitLeft2 -= 1;
            }else{
                leftLoop = false;
            }
        }else{
            leftLoop = false;
        }
    }//end while

    int resultLeft , resultRight;
    if(offsetLimitRight - offsetLimitLeft >= offsetLimitRight2 - offsetLimitLeft2){
        resultLeft = offsetLimitLeft;
        resultRight = offsetLimitRight;
    }else{
        resultLeft = offsetLimitLeft2;
        resultRight = offsetLimitRight2;
    }

    std::cout << "mid result  "<< resultLeft << "  " << resultRight << " :" <<std::endl;
    printSubStr(data , resultLeft , resultRight);
    
    (*pOffsetLeft) = resultLeft;
    (*pOffsetRight) = resultRight;
}

void findLongestSubString(const char *data , int left , int right , int *pOutLeft , int *pOutRight){
    std::cout << "[ " << left << " " << right << " ]" << std::endl;

    if(right - left == 2){ //基础情况  仅存在两个元素
        if((data[left] != data[left + 1])){
            *pOutLeft = left;
            *pOutRight = right;
            return;
        }else{
            *pOutLeft = left;
            *pOutRight = (left +1);
            return;
        }
    }else if(right - left <= 1){
        *pOutLeft = left;
        *pOutRight = (left +1);
        return;
    }

    //
    int mid = (left + right) / 2;

    int leftSolutionLeft;
    int leftSolutionRight;
    findLongestSubString(data , left , mid , &leftSolutionLeft , &leftSolutionRight);//左侧最大值
    int leftLen = leftSolutionRight - leftSolutionLeft;
    std::cout << "left solution " << std::endl;
    printSubStr(data , leftSolutionLeft , leftSolutionRight);

    int rightSolutionLeft;
    int rightSolutionRight;
    findLongestSubString(data , mid + 1 , right , &rightSolutionLeft , &rightSolutionRight); // 右侧最大值
    int rightLen = rightSolutionRight - rightSolutionLeft;
    std::cout << "right solution " << std::endl;
    printSubStr(data , rightSolutionLeft , rightSolutionRight);

    int midLeft , midRight;
    findLongsetSubStringCrossMid(data , mid , left , right , &midLeft , &midRight);
    int midLen = midRight - midLeft;
    std::cout << "mid solution  " << midLeft << "   " << midRight << " " << std::endl;
    //std::cout << "mid solution2 " << midLeft << "   " << midRight << " " << std::endl;
    printSubStr(data , midLeft , midRight);

    std::cout << "leftLen = " << leftLen << " midLen = " << midLen << "  rightLen = " << rightLen << std::endl;

    if(leftLen >= rightLen && leftLen >= midLen){
        *pOutLeft = leftSolutionLeft;
        *pOutRight = leftSolutionRight;
    }else if(midLen >= leftLen && midLen >= rightLen){
        *pOutLeft = midLeft;
        *pOutRight = midRight;
    }else if(rightLen >= leftLen && rightLen >= midLen){
        *pOutLeft = rightSolutionLeft;
        *pOutRight = rightSolutionRight;
    }
}

int lengthOfLongestSubstring(std::string s) {
    if(s == "")
        return 0;
    
    int len = s.length();

    int outputLeft;
    int outputRight;
    findLongestSubString(s.c_str() , 0 , len , &outputLeft , &outputRight);

    std::cout << "  ====== "<< s <<" ===== " << outputLeft << "  " << outputRight << std::endl;
    printSubStr(s.c_str() , outputLeft , outputRight);
    return outputRight - outputLeft;
}

int main(int argc , char *argv[]) {    
    //  bziuwnklhqzrxnb   => iuwnklhqzrx

    //bpfbhmipx => fbhmipx
    // std::string str = "bziuwnklhqzrxnb";
    // std::string str = "bpfbhmipx"; 
    // std::string str = "abcabcbb";
    std::string str = "loddktdji"; //ktdji
    int r = lengthOfLongestSubstring(str);
    std::cout << r << std::endl;

    //findLongsetSubStringCrossMid(str.c_str() , 4 , 0 , 9);
    //findLongsetSubStringCrossMid(str.c_str() , 7 , 0 , 15);
    return 0;
}


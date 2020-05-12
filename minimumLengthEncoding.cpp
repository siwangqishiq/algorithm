/***
 * 
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 

示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7
每个单词都是小写字母 。
 * 
 * */

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>

struct EncodeInfo{
    std::string content;
    int preTotalLength;
    std::vector<std::shared_ptr<std::pair<int , int>>> relatedIndexVec;
};

//根据编码单词结果 产生最终长度
int calulateEncodeWords(std::vector<EncodeInfo> &encodeWords , 
                        std::vector<std::shared_ptr<std::pair<int , int>> > &wordIndexes , bool printIndexes = false){
    std::string resultStr;
    std::vector<int> offsetVec;

    int totalLength = 0;
    for(EncodeInfo &info : encodeWords){
        info.preTotalLength = resultStr.length();
        resultStr += (info.content + std::string("#"));
    }//end for each
    
    
    if(printIndexes){
        std::vector<int> indexes;
        int offset = 0;

        for(std::shared_ptr<std::pair<int , int>> &p : wordIndexes){
            EncodeInfo &info = encodeWords[p->first];
            std::cout << info.content << std::endl;
            indexes.push_back(info.preTotalLength + p->second);
        }//end for each

        std::cout << resultStr << std::endl;

        std::cout << "indexes = [ ";
        for(int &v : indexes){
            std::cout << v << " ";
        }//end for each
        std::cout << "] " << std::endl;
    }
   
    return resultStr.length();
}

//检测checkstr 是否是 srcStr的后缀   
bool checkWordIsSuffix(std::string &srcStr , std::string &checkStr) {
    if(srcStr == checkStr)
        return true;

    if(srcStr.length() < checkStr.length())
        return false;

    int offset = srcStr.length() - checkStr.length();
    for(int i = checkStr.length() - 1 ; i >= 0 ; i--){
        if(checkStr[i] != srcStr[offset + i]){
            return false;
        }
    }

    return true;
}

int minimumLengthEncoding(std::vector<std::string>& words) {
    if(words.size() == 0)
        return 0;

    std::vector<EncodeInfo> encodeWords;
    std::vector<std::shared_ptr<std::pair<int , int>> > wordIndexes;
    
    for(int i = 0,len = words.size(); i < len ; i++){
        std::string word = words[i];

        bool isContain = false;
        for(int j=0;j<encodeWords.size();j++){
            EncodeInfo &info = encodeWords[j];
            
            if(info.content.length() >= word.length()){ //已在库中的元素比 新word要长
                if(checkWordIsSuffix(info.content , word)){//可以压缩存贮
                    std::shared_ptr<std::pair<int , int>> p = std::make_shared<std::pair<int , int>>(std::make_pair(i , info.content.length() - word.length()));
                    wordIndexes.push_back(p);
                    isContain = true;
                    break;
                }
            }else{
                if(checkWordIsSuffix(word ,info.content)){ //swap 库中的元素
                    info.content = word;
                    //adjust
                    int delta = word.length() - info.content.length();
                    for(int &v : info.relatedIndexVec){
                        wordIndexes[v].second += delta; 
                    }

                    std::pair<int , int> p = std::make_pair(i , info.content.length() - word.length());
                    wordIndexes.push_back(p);
                    isContain = true;

                    break;
                }
            }
        }//end for j

        if(!isContain){
            EncodeInfo encodeInfo;
            encodeInfo.content = word;
            encodeInfo.relatedIndex.push_back(wordIndexes.length());

            encodeWords.push_back(encodeInfo);

            std::shared_ptr<std::pair<int , int>> p =std::make_shared<std::pair<int , int>>(std::make_pair(i , 0));
            wordIndexes.push_back(p);
        }
    }//end for i
    
    return calulateEncodeWords(encodeWords , wordIndexes , true);
}

int main(int argc , char *argv[]){
    std::vector<std::string> words = {"time", "me", "bell" , "abell"};
    int result = minimumLengthEncoding(words);

    return 0;
}//end main

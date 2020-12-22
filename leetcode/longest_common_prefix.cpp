


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()){
        return "";
    }

    if(strs.size() == 1 ){
        return strs[0];
    }

    string commonPrefix = "";
    string s = strs[0];
    int index = 0;
    bool isEnd = false;
    while(index < s.length()){
        //char charVal = ;
        char charVal = s.c_str()[index];
        //cout << charVal << endl;
        for(int i = 1 ; i < strs.size();i++){
            string str = strs[i];
            if(index >= str.length()){
                isEnd = true;
                break;
            }else{
                if(charVal != str.c_str()[index]){
                    isEnd = true;
                    break;
                }
            }
        }//end for i

        if(isEnd)
            break;
        
        index++;
        commonPrefix += charVal;
    }
    

    return commonPrefix;
}

int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;

    vector<string> strs2 = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs2) << endl;

    return 0;
}
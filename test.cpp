#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

string genStrFromVector(vector<char> &vec){
    string str;
    for(char c : vec){
        str += c;
    }//end for each
    return str;
}

int lengthOfLongestSubstring(string s) {
    if(s == "")
        return 0;

    const char *data = s.c_str();
    const int len = s.length();

    vector<vector<char>> result; 

    for(int i = 0 ; i < len ;i++){
        vector<char> sub;
        unordered_set<char> set;

        sub.push_back(data[i]);
        set.insert(data[i]);

        for(int j = i + 1; j < len ; j++){
            if(set.find(data[j]) == set.end()){
                sub.push_back(data[j]);
                set.insert(data[j]);
            }else{
                break;
            }
        }//end for j
        result.push_back(sub);
    } //end for i
    
    int maxIndex = -1;
    int maxLength = -1;
    for(int i = 0 ; i < result.size();i++){
        vector<char> &item = result[i];
        cout << item.size() <<" " << genStrFromVector(item) << endl;
        if((int)item.size() > maxLength){
            maxIndex = i;
            maxLength = item.size();
        }
    }

    cout << "maxIndex = " << maxIndex << endl;
    vector<char> &longestStrVec = result[maxIndex];
    cout << genStrFromVector(longestStrVec) << endl;
    cout << "size = " << longestStrVec.size() << endl;

    return longestStrVec.size();
}

int main(){
    // string str = "bpfbhmipx";
    string str = "loddktdji";
   
    int r = lengthOfLongestSubstring(str);
    cout << r << endl;

    return 0;
}
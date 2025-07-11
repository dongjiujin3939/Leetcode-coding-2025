/*
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution{
public:
    int lengthOfLongestSubString(string s){
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            char currentChar = s[right];
            if(charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left){ // 判断字符是否已经存在，和是否在维护的窗口中
                left = charIndex[currentChar] + 1;
            }
            charIndex[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main(){
    solution sol;
    string s = {"abcabcbb"};
    int maxLength = sol.lengthOfLongestSubString(s);
    cout << "max sub string is :" << maxLength << endl;
    return 0;
}
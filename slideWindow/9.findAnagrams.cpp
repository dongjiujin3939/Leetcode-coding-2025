/*
    给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
*/

#include <iostream>
#include <vector>

using namespace std;

class solution{
public:
    vector<int> findAnagrams(string s, string p){
        int m = s.size();
        int n = p.size();
        vector<int> res;
        if(m < n){
            return res;
        }
        vector<int> sCount(26);
        vector<int> pCount(26);
        for(const auto& c : p){
            pCount[c - 'a']++;
        }
        for(int i = 0; i < m; i++){
            sCount[s[i] - 'a']++;
            if(i >= n){
                sCount[s[i - n] - 'a']--;
            }
            if(sCount == pCount){
                res.push_back(i - n + 1);
            }
        }
        return res;
    }
};

int main(){
    solution sol;
    string s = {"cbaebabacd"};
    string p = {"abc"};
    vector<int> result = sol.findAnagrams(s, p);
    cout << " res is : [ ";
    for (int index : result){
        cout << index << " ";
    }
    cout << "]" << endl;
    return 0;
}
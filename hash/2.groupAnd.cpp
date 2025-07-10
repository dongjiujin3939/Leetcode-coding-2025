/*
    给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> res;
        unordered_map<string, vector<string>> str_index;
        for(const auto& str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            str_index[sortedStr].push_back(str);
        }
        for(const auto& pair : str_index){
            res.push_back(pair.second);
        }
        return res;
    }
};

int main() {
    solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "group result: " << endl;
    for(const auto group : result){
        cout << "[ ";
        for(const auto& s : group){
            cout << s << " ";
        }
        cout << " ]" << endl;
    }

    return 0;
}
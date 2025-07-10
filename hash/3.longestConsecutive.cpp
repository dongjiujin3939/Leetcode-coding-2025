/*
    给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
    请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class solution {
public:
    int longestConsecutive(vector<int>& nums){
        int length = 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        for(int num : num_set){
            if(num_set.find(num - 1) == num_set.end()){
                int currentNum = num;
                int currentStreak = 1;
                while(num_set.find(currentNum + 1) != num_set.end()){
                    currentNum += 1;
                    currentStreak += 1;
                }
                length = max(length, currentStreak);
            }
        }
        return length;
    }
};

int main(){
    solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(nums);

    cout << " the length of the longest consecutive sequence is : " << result << endl;

    return 0;
}
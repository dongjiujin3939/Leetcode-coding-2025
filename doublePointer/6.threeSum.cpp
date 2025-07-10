/*
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
    注意：答案中不可以包含重复的三元组。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return result;
    }
};

int main(){
    solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "the result is : " << endl;
    for(const auto& triplet : result){
        cout << "[ ";
        for(int num : triplet){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
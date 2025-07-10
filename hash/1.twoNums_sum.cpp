/*
    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。你可以按任意顺序返回答案。
*/
    

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution {
public:
    vector<int> twosum(vector<int>& nums, int target){
        unordered_map<int, int> num_index;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num2 = target - nums[i];
            if(num_index.count(num2)){
                return {num_index[num2], i};
            }
            num_index[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twosum(nums, target);

    if(!result.empty()){
        cout << "ans is : [" << result[0] << ", " << result[1] << "]" << endl;
    }else {
        cout << "no ans!" << endl;
    }

    return 0;
}

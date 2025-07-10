/*
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution {
public:
    void moveZeros(vector<int>& nums){
        int start = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[start]);
                start++;
            }
        }   
    }
};

int main(){
    solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "original array : ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    sol.moveZeros(nums);
    cout << "modified array: ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
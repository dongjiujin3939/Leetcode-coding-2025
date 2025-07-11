/*
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

#include <iostream>
#include <vector>

using namespace std;

class solution{
public:
    int trap(vector<int>& height){
        int n = height.size();
        if(n < 3){
            return 0;
        }
        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= left_max){
                    left_max = height[left];
                }else{
                    water += (left_max - height[left]);
                }
                left++;
            }else{
                if(height[right] >= right_max){
                    right_max = height[right];
                }else{
                    water += (right_max - height[right]);
                }
                right--;
            }
        }
        return water;
    }
};

int main(){
    solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int water = sol.trap(height);
    cout << "water is :" << water << endl;
    return 0;
}
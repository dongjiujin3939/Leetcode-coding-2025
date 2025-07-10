/* 
    给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
    返回容器可以储存的最大水量。
    说明：你不能倾斜容器。
*/

#include <iostream>
#include <vector>

using namespace std;

class solution{
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxWater = 0;
        while(left < right){
            int area = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxWater;
    }
};

int main(){
    solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxWater = sol.maxArea(height);
    cout << "max water : " << maxWater << endl;
    return 0;
}
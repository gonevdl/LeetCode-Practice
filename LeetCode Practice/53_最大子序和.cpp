#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//动态规划算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0];
        int res = temp;
        for (int i = 1; i < nums.size(); i++) {
            temp = max(temp + nums[i], nums[i]);
            res = max(res, temp);
        }
        return res;
    }
};

int main() {
    vector<int> nums;
    for (int i = 0; i < 5000; i++) {
        srand((unsigned)time(NULL));
        int k = rand() % 700000;
        nums.push_back(k);
    }
    Solution S;
    cout << S.maxSubArray(nums) << endl;

}
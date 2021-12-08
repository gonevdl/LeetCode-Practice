#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 
，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
示例 1：
输入：nums = [2,3,2] 输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：
输入：nums = [1,2,3,1] 输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        vector<pair<int, bool>> result = vector<pair<int, bool>>((int)size, make_pair(0, false));
        result[0] = make_pair(nums[0], true);
        result[1] = make_pair(max(nums[0], nums[1]), nums[0] > nums[1] ? true : false);
        for (int i = 2; i < size; i++) {
            if (result[i - 1].first > (result[i - 2].first + nums[i])) {
                result[i] = result[i - 1];
            }
            else {
                result[i] = make_pair(result[i - 2].first + nums[i], result[i - 2].second);
            }
        }
        /*if (result[size - 2].first > (result[size - 3].first + nums[size - 1])) {
            return result[size - 2].first;
        }
        else {
            if (result[size - 3].second == false) {
                return result[size - 3].first + nums[size - 1];
            }
            else {
                return result[size - 2].first;
            }
        }*/
        if (result[size - 1].second) {
            if (nums[size - 1] > result[size - 2].first) return nums[size - 1];
            else return result[size - 2].first;
        }
        else {
            return result[size - 1].first;
        }
    }
};
int main() {
    Solution S;
    vector<int> nums = { 1,1,3,6,7,10,7,1,8,5,9,1,4,4,3 };
    cout << S.rob(nums) << endl;
    return 0;
}
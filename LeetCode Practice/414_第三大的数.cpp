#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*
414. 第三大的数
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
示例 1：
输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。
示例 2：
输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。
示例 3：
输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int, int> m;
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        else if (nums.size() == 1) {
            return nums[0];
        }

        else {
            int count = 0;
            map<int, int>::iterator it1;
            for (int i = 0; i < nums.size(); i++) {
                it1 = m.find(nums[i]);
                if (it1 == m.end()) {
                    m.insert(make_pair(nums[i], count));
                    count++;
                }
            }
            map<int, int>::iterator it = m.end();
            if (m.size() < 3) {
                if (m.size() == 1) {
                    it--;
                    return (*it).first;
                }
                else {
                    it--;
                    return (*it).first;
                }
            }
            for (int i = 0; i < 3; i++) {
                it--;

            }
            return (*it).first;
        }
    }
};

int main() {
    Solution S;
    vector<int> nums = { 2,2,3,1,1,1,1,1,1,2,2,2,3,3,0,0,0 };
    cout << S.thirdMax(nums) << endl;
    // cout << "414" << endl;
}
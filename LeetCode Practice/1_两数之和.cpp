#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //设置一个哈希表用于存放对应的数据和下标，其中，数据作为key
        multimap<int, int> m_numIndex;
        int count = 0;
        for (int num : nums) {
            //将数组中的每一个元素的下标及数字都放在哈希表中
            m_numIndex.insert(make_pair(num, count));
            count++;
        }
        vector<int> result;
        for (multimap<int, int>::iterator it = m_numIndex.begin(); it != m_numIndex.end(); it++) {
            //给定一个数，求另一个数的值
            int remainder = target - (*it).first;
            //如果找到另一个数并且其数组下标不同
            multimap<int, int>::iterator flag = m_numIndex.find(remainder);
            if (flag != m_numIndex.end() && (*flag).second != (*it).second) {
                result.push_back((*it).second);
                result.push_back((*flag).second);
                return result;
            }
        }
    }
};

int main() {
    Solution S;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    vector<int> result = S.twoSum(nums, 13);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
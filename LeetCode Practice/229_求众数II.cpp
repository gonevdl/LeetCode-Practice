#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
示例 1：
输入：[3,2,3]输出：[3]
示例 2：
输入：nums = [1]输出：[1]
示例 3：
输入：[1,1,1,3,3,2,2,2]输出：[1,2]

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> result = {};
        if (size == 0) return result;
        if (size == 1) {
            result.push_back(nums[0]);
            return result;
        }
        if (size == 2) {
            if (nums[0] == nums[1]) {
                result.push_back(nums[0]);
                return result;
            }
            else {
                return nums;
            }
        }

        map<int, int> count;
        for (int i = 0; i < size; i++) {
            if (count.find(nums[i]) == count.end()) {
                count.insert(make_pair(nums[i], 1));
            }
            else {
                count[nums[i]]++;
            }
        }

        int flag = 0;
        for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
            if ((*it).second > (size / 3)) {
                result.push_back((*it).first);
                flag++;
                if ((*it).second > ((2 * size) / 3)) {
                    return result;
                }
                if (flag == 2)
                    break;
            }
        }
        return result;
    }
};

int main() {

    Solution S;
    vector<int> nums = { 1,1,1,1,1,1,1,3,3,2,2,2 };
    for (int num : S.majorityElement(nums)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
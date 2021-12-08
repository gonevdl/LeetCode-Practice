#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;


/*
给定一个整数数组，判断是否存在重复元素。
如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
示例 1:
输入: [1,2,3,1]
输出: true
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int temp = *it;
            bool flag = true;
            vector<int>::iterator it3 = it;
            it3++;
            for (vector<int>::iterator it2 = it3; it2 != nums.end(); it2++) {
                if (temp == *it2) {
                    return flag;
                }
            }
        }
        return false;
    }
};
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            if (s.find(num) != s.end()) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    Solution S;
    Solution1 S1;
    cout << S.containsDuplicate(nums) << endl;
    cout << S1.containsDuplicate(nums) << endl;

}
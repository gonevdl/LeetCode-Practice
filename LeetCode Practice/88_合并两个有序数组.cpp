#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。

合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int pos1 = 0;
        int pos2 = 0;
        while (pos1 != m && pos2 != n) {
            if (nums1[pos1] >= nums2[pos2]) {
                nums.push_back(nums2[pos2]);
                pos2++;
            }
            else if (nums1[pos1] < nums2[pos2]) {
                nums.push_back(nums1[pos1]);
                pos1++;
            }
        }
        while (pos1 != m) {
            nums.push_back(nums1[pos1]);
            pos1++;
        }
        while (pos2 != n) {
            nums.push_back(nums2[pos2]);
            pos2++;
        }
        for (int i = 0; i < nums.size(); i++) {
            nums1[i] = nums[i];
        }
    }
};

int main() {
    Solution S;
    vector<int> nums1 = { 2,0 };
    vector<int> nums2 = { 1 };
    int m = 1;
    int n = 1;
    S.merge(nums1, m, nums2, n);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
}
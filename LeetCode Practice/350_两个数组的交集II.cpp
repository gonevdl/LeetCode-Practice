#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
给定两个数组，编写一个函数来计算它们的交集。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]      输出：[2,2]
示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]     输出：[4,9]
说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        //用一个哈希表存储数组
        multimap<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m.insert(make_pair(nums1[i], i));
        }
        for (int i = 0; i < nums2.size(); i++) {
            multimap<int, int>::iterator it = m.find(nums2[i]);
            //如果第二个数组中的元素出现在了哈希表中，则将该元素从哈希表中删除
            if (it != m.end()) {
                result.push_back((*it).first);
                m.erase(it);
                if (m.size() == 0) {
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution S;
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };
    vector<int> nums3 = { 4,9,5 };
    vector<int> nums4 = { 9, 4, 9, 8, 4 };
    vector<int> result1 = S.intersect(nums1, nums2);
    vector<int> result2 = S.intersect(nums3, nums4);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
}
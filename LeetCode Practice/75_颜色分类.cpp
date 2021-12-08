#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：
输入：nums = [2,0,1]
输出：[0,1,2]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return ;
        if (size == 1) return ;

        map<int, int> count;
        count.insert(make_pair(0, 0));
        count.insert(make_pair(1, 0));
        count.insert(make_pair(2, 0));
        for (int num : nums) {
            count[num]++;
        }

        for (int i = 0; i < count[0]; i++) {
            nums[i] = 0;
        }
        for (int i = count[0]; i < (count[0] + count[1]); i++) {
            nums[i] = 1;
        }
        for (int i = (count[0] + count[1]); i < size; i++) {
            nums[i] = 2;
        }
        return;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return;
        if (size == 1) return;
        int p = 0;
        int q = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                int temp = nums[i];
                nums[i] = nums[q];
                nums[q] = temp;
                q++;
            }
            else if (nums[i] == 0) {
                int temp = nums[i];
                nums[i] = nums[p];
                nums[p] = temp;
                if (q > p) {
                    int temp = nums[i];
                    nums[i] = nums[q];
                    nums[q] = temp;
                }
                p++;
                q++;
            }
        }
        return;
    }
};
int main() {
    Solution S;
    vector<int> nums = { 2,2,1,1,2,2,2,2,2,2 };
    S.sortColors(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
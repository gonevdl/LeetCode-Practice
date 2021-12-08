#include<iostream>
#include<vector>
using namespace std;

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = -1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                break;
            }
            pos = i;
        }
        if (pos == -1) {
            digits[digits.size() - 1]++;
            return digits;
        }
        else {
            if (pos == 0) {
                vector<int> result = vector<int>(digits.size() + 1, 0);
                result[0] = 1;
                return result;
            }
            else {
                for (int i = digits.size() - 1; i >= pos; i--) {
                    digits[i] = 0;
                }
                digits[pos - 1]++;
                return digits;
            } 
        }
    }
};

int main() {
    Solution S;
    vector<int> v1 = { 1,2,3 };
    vector<int> v2 = { 9,9,9,9,9 };
    vector<int> v3 = { 5,6,7,8,9 };
    for (int num : S.plusOne(v1)) {
        cout << num << " ";
    }
    cout << endl;
    for (int num : S.plusOne(v2)) {
        cout << num << " ";
    }
    cout << endl;
    for (int num : S.plusOne(v3)) {
        cout << num << " ";
    }
    cout << endl;
}
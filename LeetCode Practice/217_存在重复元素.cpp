#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;


/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
ʾ�� 1:
����: [1,2,3,1]
���: true
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/contains-duplicate
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*
414. ���������
����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������
ʾ�� 1��
���룺[3, 2, 1]
�����1
���ͣ������������ 1 ��
ʾ�� 2��
���룺[1, 2]
�����2
���ͣ����������������, ���Է��������� 2 ��
ʾ�� 3��
���룺[2, 2, 3, 1]
�����1
���ͣ�ע�⣬Ҫ�󷵻ص������������ָ�����в�ͬ�������ŵ����������
�����д�������ֵΪ 2 ���������Ƕ��ŵڶ��������в�ͬ�������ŵ��������Ϊ 1 ��
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
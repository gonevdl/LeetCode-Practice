#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
�����������飬��дһ���������������ǵĽ�����
ʾ�� 1��
���룺nums1 = [1,2,2,1], nums2 = [2,2]      �����[2,2]
ʾ�� 2:
���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]     �����[4,9]
˵����
��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ִ�������Сֵһ�¡�
���ǿ��Բ�������������˳��
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        //��һ����ϣ��洢����
        multimap<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m.insert(make_pair(nums1[i], i));
        }
        for (int i = 0; i < nums2.size(); i++) {
            multimap<int, int>::iterator it = m.find(nums2[i]);
            //����ڶ��������е�Ԫ�س������˹�ϣ���У��򽫸�Ԫ�شӹ�ϣ����ɾ��
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
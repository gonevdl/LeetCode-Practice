#include<iostream>
using namespace std;
/*
* ���� ��ά ƽ�������� ��ֱ�߹��ɵ� ���Σ�������㲢�����������θ��ǵ��������
ÿ���������� ���� ����� ���� ���������ʾ��
��һ�������������¶��� (ax1, ay1) �����϶��� (ax2, ay2) ���塣
�ڶ��������������¶��� (bx1, by1) �����϶��� (bx2, by2) ���塣
���룺ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
�����45
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rectangle-area
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //�����ж����������Ƿ��н���
        //���û��
        if (by1 > ay2 || bx1 > ax2 || by2 < ay1 || bx2 < ax1) {
            int s = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
            return s;
        }
        else {
            int temp = (min(ax2, bx2) - max(ax1, bx1)) * (min(by2, ay2) - max(ay1, by1));
            int s = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - temp;
            return s;
        }
    }
};
int main() {
    Solution S;
    int ax1 = -5;
    int ay1 = -5;
    int ax2 = 0;
    int ay2 = -4;
    int bx1 = -3;
    int by1 = -3;
    int bx2 = 3;
    int by2 = 3;
    cout << S.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
}
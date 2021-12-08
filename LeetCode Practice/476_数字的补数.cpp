#include<iostream>
#include<vector>
using namespace std;

/*
����һ�� �� ���� num ��������Ĳ����������ǶԸ����Ķ����Ʊ�ʾȡ��.
ʾ�� 1��
���룺num = 5
�����2
���ͣ�5 �Ķ����Ʊ�ʾΪ 101��û��ǰ����λ�����䲹��Ϊ 010����������Ҫ��� 2 ��
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-complement
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int findComplement(int num) {
        int bit = this->getBits(num);
        int temp = 0;
        for (int i = 0; i < bit; i++) {
            temp += pow(2, i);
        }
        return num ^ temp;
    }
    int getBits(int num) {
        int bit = 0;
        while (true) {
            num = num / 2;
            bit++;
            if (num == 0) break;
        }
        return bit;
    }
};

int main() {
    Solution S;
    int num = 5;
    cout << S.findComplement(num) << endl;
    return 0;
}
#include<iostream>
using namespace std;

/*
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������
*/


//��¥�ݵ�ʱ�򣬵�n>3ʱ����n��̨�׵ķ��������ɵ� n-2 ��̨�����������ߵ� n-1 ��
//̨����1���õ�
class Solution {
public:
    int climbStairs(int n) {
        int p = 0;
        int q = 1;
        int r = 1;
        for (int i = 0; i < n - 1; i++) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main() {
    Solution S;
    for (int i = 2; i < 30; i++) {
        cout << S.climbStairs(i) << endl;
    }
    return 0;
}
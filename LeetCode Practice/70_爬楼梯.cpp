#include<iostream>
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/


//爬楼梯的时候，当n>3时，第n个台阶的方法可以由第 n-2 个台阶爬两步或者第 n-1 个
//台阶爬1步得到
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
#include<iostream>
#include<vector>
using namespace std;

/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给你 n ，请计算 F(n) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
0
1
1
2
4
7
13
24
44
81
149
274
504
927
1705
3136
5768
10609
19513
35890
66012
121415
223317
410744
755476
1389537
2555757
4700770
8646064
15902591
29249425
53798080
98950096
181997601
334745777
615693474
1132436852
2082876103
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        result.push_back(1);
        for (int i = 3; i <= n; i++) {
            int temp = 0;
            temp = temp + result[i - 1] + result[i - 2] + result[i - 3];
            result[i - 3] = result[i - 2];
            result.push_back(temp);
        }
        return result[result.size() - 1];
    }
};

int main() {
    Solution S;
    for (int i = 0; i < 38; i++) {
        cout << S.fib(i) << endl;
    }
}

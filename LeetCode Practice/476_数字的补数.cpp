#include<iostream>
#include<vector>
using namespace std;

/*
给你一个 正 整数 num ，输出它的补数。补数是对该数的二进制表示取反.
示例 1：
输入：num = 5
输出：2
解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-complement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
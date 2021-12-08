#include<iostream>
using namespace std;

/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long divedend1 = (long long)abs((long long)dividend);
        long long divisor1 = (long long)abs((long long)divisor);
        /*cout << divi_bit << endl;
        cout << dive_bit << endl;*/
        long long n = 0;
        long long r = 0;
        int divi_bit = this->getBitsOfNumber(divisor1);
        while (true) {
            int dive_bit = this->getBitsOfNumber(divedend1);
            if (dive_bit <= divi_bit) {
                if (divedend1 >= divisor1) {
                    n += 1;
                }
                else {
                    n = n;
                }
                break;
            }
            r = divedend1 - (divisor1 << (dive_bit - divi_bit));
            if (r < 0) {
                r= divedend1 - (divisor1 << (dive_bit - divi_bit - 1));
                n += (long long)1 << (dive_bit - divi_bit - 1);
            }
            else n += (long long)1 << (dive_bit - divi_bit);
            divedend1 = r;
        }
        if ((divisor <= 0 && dividend <= 0) || (divisor > 0 && dividend > 0)) {
            if (n < pow(-2, 31) || n > (pow(2, 31) - 1))
                return pow(2, 31) - 1;
            return n;
        }
        else {
            if (n < pow(-2, 31) || n > pow(2, 31))
                return pow(2, 31) - 1;
            return -n;
        }
    }

    int getBitsOfNumber(int num) {
        int result = 0;
        long long num1 = (long long)abs((long long)num);
        while (true) {
            num1 = num1 >> 1;
            result++;
            if (num1 == 0) return result;
        }
    }
};

int main() {
    Solution S;
    int dividend = pow(-2,31);
    int divisor = 1;
    cout << S.divide(dividend, divisor) << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<sstream>
#include<stdlib.h>
using namespace std;

/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
如果小数部分为循环小数，则将循环的部分括在括号内。如果存在多个答案，只需返回 任意一个 。
对于所有给定的输入，保证 答案字符串的长度小于 104 。
输入：numerator = 1, denominator = 2   输出："0.5"
输入：numerator = 2, denominator = 1   输出："2"
输入：numerator = 2, denominator = 3   输出："0.(6)"
输入：numerator = 4, denominator = 333   输出："0.(012)"
输入：numerator = 1, denominator = 5   输出："0.2"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//从余数相同后的下一个商开始循坏

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        //先取绝对值，最后判断符号
        long long numerator_abs = abs((long long)numerator);
        long long denominator_abs = abs((long long)denominator);
        long long quotient = numerator_abs / denominator_abs;
        long long remainder = numerator_abs % denominator_abs;

        /*cout << numerator_abs << " " << denominator_abs << endl;
        cout << quotient << " " << remainder << endl;*/
        //判断符号
        string symbol = "";
        if ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0)) {
        }
        else {
            symbol += "-";
        }
        //建立一个数组和一个哈希表，将商存储在数组中，哈希表存储与商对应的余数
        vector<string> v_quotient;
        map<long long, long long> m_remainder;
        stringstream temp;
        m_remainder.insert(make_pair(remainder, 0));
        temp << quotient;
        //temp >> v_quotient[0];
        string str;
        temp >> str;
        v_quotient.push_back(str);
        temp.clear();
        //如果可以整除，则直接输出整除
        if (remainder == 0) {
            return symbol + v_quotient[0];
        }
        //不能整除，开始计算小数部分
        else{
            //循环计算，如果余数为0，则可以除尽，输出数组中的商，并加上小数点
            int count = 1;
            map<long long, long long>::iterator flag;
            while (remainder != 0) {
                remainder *= 10;
                //求新的商，这是小数点后的商
                quotient = remainder / denominator_abs;
                //求新的余数，余数相等时则开始从余数相等的下一开始循环
                remainder = remainder % denominator_abs;
                stringstream temp1;
                temp1 << quotient;
                temp1 >> str;
                v_quotient.push_back(str);
                //cout << v_quotient[count] << " " << remainder << " " << endl;
                //如果不能够在map中找到相同的余数，则插入
                if (m_remainder.find(remainder) == m_remainder.end()) {
                    m_remainder.insert(make_pair(remainder, count));
                }
                //如果找到相同的余数，说明是无限循环小数
                else {
                    flag = m_remainder.find(remainder);
                    break;
                } 
                count++;
            }
            string result = symbol + v_quotient[0] + ".";
            if (remainder == 0) {
                //当循环结束，余数为0，也就是除尽了，则输出

                for (int i = 1; i < v_quotient.size(); i++) {
                    result += v_quotient[i];
                }
                return result;
            }
            //如果余数不是0，则从余数相同的位置的下一个开始循环
            else {
                for (int i = 1; i <= (*flag).second; i++) {
                    result = result + v_quotient[i];
                }
                result += "(";
                for (int j = (*flag).second + 1; j <= count; j++) {
                    result += v_quotient[j];
                }
                result += ")";
                return result;
            }   
        }
    }
};
int main() {
    Solution S;
    int numerator = -2147483648;
    int denominator = -1;
    cout << S.fractionToDecimal(numerator, denominator) << endl;
}
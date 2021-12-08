#include<iostream>
#include<vector>
using namespace std;

/*
*给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
注意:
十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，
十六进制字符串中的第一个字符将不会是0字符。 
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
示例 1：
输入:26
输出:"1a"
示例 2：
输入:-1
输出:"ffffffff"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
* 
*/

class Solution {
public:
    string toHex(int num) {
        string hex_index = "0123456789abcdef";
        string hex = "";
        if (num == 0) {
            hex = "0";
            return hex;
        }
        else if (num > 0) {
            vector<int> v;
            while (num != 0) {
                int temp = num & 15;
                num = num >> 4;
                v.push_back(temp);
            }
            for (int i = v.size(); i > 0; i--) {
                hex += hex_index[v[i - 1]];
            }
            return hex;
        }
        else {
            long int hex_num = num + 4294967296;
            /*int hex_num = inverse ^ 2147483647;
            hex_num = hex_num + 1;*/
            vector<int> v;
            for (int i = 0; i < 8; i++) {
                int temp = hex_num & 15;
                hex_num = hex_num >> 4;
                v.push_back(temp);
            }   
            for (int i = v.size(); i > 0; i--) {
                hex += hex_index[v[i - 1]];
            }
            return hex;
        }
    }
};

int main() {
    int num1 = 26;
    int num2 = 2634;
    int num3 = 1234567890;
    int num4 = -1;
    int num5 = -2147483648;
    Solution S;
    //string s1 = S.toHex(num1);
    //string s2 = S.toHex(num2);
    cout << S.toHex(num1) << endl;
    cout << S.toHex(num2) << endl;
    cout << S.toHex(num3) << endl;
    cout << S.toHex(num4) << endl;
    cout << S.toHex(num5) << endl;
}

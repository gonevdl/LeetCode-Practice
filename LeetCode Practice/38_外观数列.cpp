#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
给定一个正整数 n ，输出外观数列的第 n 项。
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
你可以将其视作是由递归公式定义的数字字符串序列：
countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string countAndSay(int n) {
        string p = "0";
        string q = "1";
        //string num = to_string(n);
        if (n == 1) return to_string(1);
        for (int i = 1; i < n; i++) {
            p = "";
            unordered_map<char, int> temp;
            for (int j = 0; j < q.size(); j++) {
                if (temp.find(q[j]) == temp.end()) {
                    if (j != 0) {
                        p += to_string(temp[q[j - 1]]) + q[j - 1];
                        temp.clear();
                    }
                    temp.insert(make_pair(q[j], 1));
                }
                else {
                    temp[q[j]]++;
                }
            }
            /*q = "";
            for (unordered_map<char, int>::iterator it = temp.begin(); it != temp.end(); it++) {
                q += to_string((*it).second) + (*it).first;
            }*/
            p += to_string((*temp.begin()).second) + (*temp.begin()).first;
            q = p;
        }
        return q;
    }
};

int main() {
    Solution S;
    int num3 = 1;
    int num1 = 4;
    int num2 = 7;
    cout << S.countAndSay(num3) << endl;
    cout << S.countAndSay(num1) << endl;
    cout << S.countAndSay(num2) << endl;
    return 0;
}
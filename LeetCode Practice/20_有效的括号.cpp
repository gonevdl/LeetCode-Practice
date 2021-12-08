#include<iostream>
#include<stack>
using namespace std;
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
示例 1：输入：s = "()"输出：true
示例 2：输入：s = "()[]{}"输出：true
示例 3：输入：s = "(]"输出：false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        if (s.size() == 0 || s.size() == 1) return false;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i])
            {
            case '(':
                brackets.push(s[i]);
                break;
            case '{':
                brackets.push(s[i]);
                break;
            case '[':
                brackets.push(s[i]);
                break;
            case ')':
            {   //括号匹配的前提是，栈中要存有括号
                if (brackets.size() != 0 && brackets.top() == '(') {
                    brackets.pop();
                    break;
                }
                else return false;
            }
            case '}':
            {
                if (brackets.size() != 0 && brackets.top() == '{') {
                    brackets.pop();
                    break;
                }
                else return false;
            }
            case ']':
            {
                if (brackets.size() != 0 && brackets.top() == '[') {
                    brackets.pop();
                    break;
                }
                else return false;
            }
            default:
                break;
            }
        }
        if (brackets.size() == 0) {
            return true;
        }
        else return false;
    }
};

int main() {
    Solution S;
    string s1 = "(){}({}){{{}}}{{{(([[]]))}}}";
    string s2 = "{{{}}}(({{}})){}({)}";
    string s3 = "{";
    cout << S.isValid(s1) << " " << S.isValid(s2) << " " << S.isValid(s3) << endl;
    return 0;
}
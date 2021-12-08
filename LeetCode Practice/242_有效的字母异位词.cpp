#include<iostream>
#include<map>
#include<string>
using namespace std;

/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"  输出: true
示例 2:
输入: s = "rat", t = "car"  输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> count;
        for (char ch : s) {
            count[ch]++;
        }
        bool flag = true;
        for (int i = 0; i < t.size(); i++) {
            if (count.find(t[i]) != count.end()) {
                if (count[t[i]] >= 0) {
                    count[t[i]]--;
                    if (count[t[i]] < 0) {
                        flag = false;
                    }
                }
            }
            else {
                flag = false;
            }
        }
        return flag;
    }
};

int main() {
    Solution S;
    string s = "anagran";
    string t = "nagaram";
    cout << S.isAnagram(s, t) << endl;
    return 0;
}
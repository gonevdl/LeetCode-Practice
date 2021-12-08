#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能
由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。
杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
示例 1：
输入：ransomNote = "a", magazine = "b"输出：false
示例 2：
输入：ransomNote = "aa", magazine = "ab"输出：false
示例 3：
输入：ransomNote = "aa", magazine = "aab"输出：true
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for (char ch : magazine) {
            count[ch]++;
            //cout << count[ch] << endl;
        }
        bool flag = true;
        for (int i = 0; i < ransomNote.size(); i++) {
            if (count.find(ransomNote[i]) != count.end()) {
                if (count[ransomNote[i]] >= 0) {
                    count[ransomNote[i]]--;
                    if (count[ransomNote[i]] < 0) {
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
    string ransomNote = "aa";
    string magazine = "ab";
    cout << S.canConstruct(ransomNote, magazine);
    return 0;
}
#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
示例：
s = "leetcode"
返回 0
s = "loveleetcode"
返回 2
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0) return -1;
        if (s.size() == 1) return 0;
        map<char, int> count;
        for (int i = 0; i < s.size(); i++) {
            if (count.find(s[i]) == count.end()) {
                count.insert(make_pair(s[i], 1));
            }
            else {
                (*(count.find(s[i]))).second++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution S;
    string s = "leetcode";
    cout << S.firstUniqChar(s) << endl;
    return 0;
}
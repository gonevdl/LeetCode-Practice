#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
ʾ����
s = "leetcode"
���� 0
s = "loveleetcode"
���� 2
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/first-unique-character-in-a-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

/*
����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ���
�ɵڶ����ַ��� magazines ������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��
(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��
��־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)
ʾ�� 1��
���룺ransomNote = "a", magazine = "b"�����false
ʾ�� 2��
���룺ransomNote = "aa", magazine = "ab"�����false
ʾ�� 3��
���룺ransomNote = "aa", magazine = "aab"�����true
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/ransom-note
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
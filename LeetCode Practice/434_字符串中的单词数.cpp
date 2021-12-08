#include<iostream>
#include<string>
using namespace std;

/*
ͳ���ַ����еĵ��ʸ���������ĵ���ָ���������Ĳ��ǿո���ַ���
��ע�⣬����Լٶ��ַ����ﲻ�����κβ��ɴ�ӡ���ַ���
ʾ��:
����: "Hello, my name is John"
���: 5
����: ����ĵ�����ָ�����Ĳ��ǿո���ַ������� "Hello," ���� 1 �����ʡ�
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-segments-in-a-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        //int endOfs = s.rfind(' ', 0);
        if (s.size() == 0) return 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != ' ' && s[i + 1] == ' ') {
                count++;
            }
        }
        if (s[s.size() - 1] != ' ') {
            count++;
        }
        return count;
    }
};

int main() {
    Solution S;
    string s = "Hello, my name is John  ";
    cout << S.countSegments(s) << endl;
    return 0;
}
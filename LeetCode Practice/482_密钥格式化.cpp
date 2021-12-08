#include<iostream>
#include<string>
using namespace std;

/*
��һ����Կ�ַ��� S ��ֻ������ĸ�������Լ� '-'�����ۺţ������У� N �� '-' ���ַ����ֳ��� N+1 �顣
����һ������ K���������¸�ʽ���ַ�����ʹÿ������ǡ�ð��� K ���ַ����ر�أ���һ������������ַ���������С�ڵ��� K��
������Ҫ���� 1 ���ַ�����������֮����Ҫ�� '-'�����ۺţ����������ҽ����е�Сд��ĸת��Ϊ��д��ĸ��
�����ǿ��ַ��� S ������ K���������������Ĺ�����и�ʽ����
ʾ�� 1��
���룺S = "5F3Z-2e-9-w", K = 4
�����"5F3Z-2E9W"
���ͣ��ַ��� S ���ֳ����������֣�ÿ���� 4 ���ַ��� ע�⣬������������ۺ���Ҫɾ����
ʾ�� 2��
���룺S = "2-5g-3-J", K = 2
�����"2-5G-3J"
���ͣ��ַ��� S ���ֳ��� 3 �����֣�����ǰ��Ĺ�����������һ���ֵ��ַ��������ڸ��������������ಿ�ֽ�Ϊ 2 ���ַ���
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/license-key-formatting
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0;
        reverse(s.begin(), s.end());
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '-') {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] -= 32;
                }
                result += s[i];
                count++;
            }
            if (count == k) {
                count = 0;
                result += "-";
            }
        }
        if (result == "") return result;
        else if (result[result.size() - 1] == '-') {
            string::iterator flag = result.end();
            flag--;
            result.erase(flag);
            reverse(result.begin(), result.end());
            return result;
        }
        else {
            reverse(result.begin(), result.end());
            return result;
        }
    }
};

int main() {
    Solution S;
    string str1 = "5F3Z-2e-9-w";
    int k1 = 4;
    string str2 = "2-5g-3-J";
    int k2 = 2;
    string str3 = "---";
    int k3 = 3;
    cout << S.licenseKeyFormatting(str1, k1) << endl;
    cout << S.licenseKeyFormatting(str2, k2) << endl;
    cout << S.licenseKeyFormatting(str3, k3) << endl;
}
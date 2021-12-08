#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*
����һ�������� n �����������еĵ� n �
��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
����Խ����������ɵݹ鹫ʽ����������ַ������У�
countAndSay(1) = "1"
countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ�����
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-and-say
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
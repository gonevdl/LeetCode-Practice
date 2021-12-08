#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

/*
���� DNA ����һϵ����дΪ 'A'��'C'��'G' �� 'T' �ĺ�������ɣ����磺"ACGAATTCCG"�����о� DNA ʱ��
ʶ�� DNA �е��ظ�������ʱ����о��ǳ��а�����
��дһ���������ҳ�����Ŀ���Ӵ���Ŀ���Ӵ��ĳ���Ϊ 10������ DNA �ַ��� s �г��ִ�������һ�Ρ�
ʾ�� 1��
���룺s = "AAAAA CCCCC AAAAA CCCCC CAAAA AGGGT TT"�����["AAAAACCCCC","CCCCCAAAAA"]
ʾ�� 2��
���룺s = "AAAAA AAAAA AAA"�����["AAAAAAAAAA"]  AAAAA AAAAA AAA
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/repeated-dna-sequences
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> count;
        vector<string> result;
        if (s.size() <= 10) {
            result.push_back(s);
            return result;
        }
        for (int i = 0; i < s.size() - 9; i++) {
            string temp;
            temp.append(s, i, 10);
            map<string, int>::iterator it = count.find(temp);
            if (it != count.end()) {
                (*it).second++;
            }
            else {
                count.insert(make_pair(temp, 1));
            }
        }
        for (map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
            if ((*it).second > 1) {
                result.push_back((*it).first);
            }
        }
        return result;
    }
};

int main() {
    Solution S;
    string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s2 = "AAAAAAAAAAAAA";
    vector<string> result1;
    vector<string> result2;
    result1 = S.findRepeatedDnaSequences(s1);
    result2 = S.findRepeatedDnaSequences(s2);
    for (string str : result1) {
        cout << str << ",";
    }
    cout << endl;
    for (string str : result2) {
        cout << str << ",";
    }
    cout << endl;
}
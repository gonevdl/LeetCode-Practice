#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
352. ����������Ϊ������ཻ����
 ����һ���ɷǸ����� a1, a2, ..., an ��ɵ����������룬���㽫��ĿǰΪֹ�����������ܽ�Ϊ���ཻ�������б�
ʵ�� SummaryRanges �ࣺ
SummaryRanges() ʹ��һ������������ʼ������
void addNum(int val) ���������м������� val ��
int[][] getIntervals() �Բ��ཻ���� [starti, endi] ���б���ʽ���ض����������������ܽᡣ
ʾ����
���룺
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", 
"addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
�����
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, 
[[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
���ͣ�
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // ���� [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // ���� [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // ���� [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // ���� [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // ���� [[1, 3], [6, 7]]
*/

class SummaryRanges {
public:
    SummaryRanges() {
        m_Size = 0;
    }

    void addNum(int val) {
        if (m_Map.find(val) != m_Map.end()) {
        }
        else {
            m_Map.insert(make_pair(val, val));
            m_Size++;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result = {};
        vector<int> temp = {};
        if (m_Size == 0) {
            return result;
        }
        else if (m_Size == 1) {
            map<int, int>::iterator it = m_Map.begin();
            temp.push_back((*it).first);
            temp.push_back((*it).first);
            result.push_back(temp);
            return result;
        }
        map<int, int>::iterator it = m_Map.begin();
        int start = (*it).first;
        int end = (*it).first;
        temp.push_back(start);
        temp.push_back(end);
        for (int i = 0; i < m_Size; i++) {
            /*if (m_Arr[i + 1] == start + 1) {
                end = m_Arr[i + 1];
                temp.pop_back();
                temp.push_back(end);
            }
            else {
                start = m_Arr[i + 1];
                end = m_Arr[i + 1];
                result.push_back(temp);
            }*/
            map<int, int>::iterator it1 = it;
            it1++;
            if (it1 != m_Map.end()) {
                if ((*it1).first == ((*it).first + 1)) {
                    end = (*it1).first;
                    temp.pop_back();
                    temp.push_back(end);
                }
                else {
                    result.push_back(temp);
                    temp.clear();
                    start = end = (*it1).first;
                    temp.push_back(start);
                    temp.push_back(end);
                }
                it++;
            }
            else {
                break;
            }
        }
        result.push_back(temp);
        return result;
    }
private:
    map<int,int> m_Map;
    int m_Size;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main() {
    SummaryRanges* summaryRanges = new SummaryRanges();
    summaryRanges->addNum(1);      // arr = [1]
    vector<vector<int>> result = summaryRanges->getIntervals(); // ���� [[1, 1]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(3);      // arr = [1, 3]
    result = summaryRanges->getIntervals(); // ���� [[1, 1], [3, 3]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(7);      // arr = [1, 3, 7]
    result = summaryRanges->getIntervals(); // ���� [[1, 1], [3, 3], [7, 7]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(2);      // arr = [1, 2, 3, 7]
    result = summaryRanges->getIntervals(); // ���� [[1, 3], [7, 7]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(6);      // arr = [1, 2, 3, 6, 7]
    result = summaryRanges->getIntervals(); // ���� [[1, 3], [6, 7]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
}
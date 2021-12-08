#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
352. 将数据流变为多个不相交区间
 给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。
实现 SummaryRanges 类：
SummaryRanges() 使用一个空数据流初始化对象。
void addNum(int val) 向数据流中加入整数 val 。
int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
示例：
输入：
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", 
"addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
输出：
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, 
[[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
解释：
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // 返回 [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
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
    vector<vector<int>> result = summaryRanges->getIntervals(); // 返回 [[1, 1]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(3);      // arr = [1, 3]
    result = summaryRanges->getIntervals(); // 返回 [[1, 1], [3, 3]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(7);      // arr = [1, 3, 7]
    result = summaryRanges->getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(2);      // arr = [1, 2, 3, 7]
    result = summaryRanges->getIntervals(); // 返回 [[1, 3], [7, 7]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
    summaryRanges->addNum(6);      // arr = [1, 2, 3, 6, 7]
    result = summaryRanges->getIntervals(); // 返回 [[1, 3], [6, 7]]
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
}
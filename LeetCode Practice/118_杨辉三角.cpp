﻿#include<iostream>
#include<vector>
using namespace std;

/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。在「杨辉三角」中，每个数是它左上方和右上方的数的和。
示例 1:
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:
输入: numRows = 1
输出: [[1]]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> temp = { 1 };
        if (numRows == 1) {
            result.push_back(temp);
            return result;
        }
        else {
            result.push_back(temp);
            vector<int> tmp;
            for (int i = 1; i < numRows; i++) {
                for (int j = 0; j <= i; j++) {
                    if (j == 0) {
                        tmp.push_back(result[i - 1][0]);
                    }
                    else if (j == i) {
                        tmp.push_back(result[i - 1][i - 1]);
                    }
                    else tmp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
                result.push_back(tmp);
                tmp.clear();
            }
            return result;
        }
    }
};

int main() {
    Solution S;
    for (int i = 0; i < 5; i++) {
        int numRows = rand() % 5 + 10;
        vector<vector<int>> result = S.generate(numRows);
        for (vector<int> v : result) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    /*int numRows = 18;
    vector<vector<int>> result = S.generate(numRows);
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }*/
}
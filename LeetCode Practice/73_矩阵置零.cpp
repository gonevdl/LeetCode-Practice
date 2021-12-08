#include<iostream>
#include<vector>
using namespace std;

/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
进阶：
一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
示例 1：输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]  输出：[[1,0,1],[0,0,0],[1,0,1]]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //先记下为0的元素的位置
        vector<vector<int>> position;
        vector<int> temp;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    temp.push_back(i);
                    temp.push_back(j);
                    position.push_back(temp);
                    temp.clear();
                }
            }
        }
        for (int i = 0; i < position.size(); i++) {
            for (int k = 0; k < matrix[0].size(); k++) {
                matrix[position[i][0]][k] = 0;
            }
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][position[i][1]] = 0;
            }
        }
    }
};

int main() {
    Solution S;
    vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
    S.setZeroes(matrix);
    for (vector<int> row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}
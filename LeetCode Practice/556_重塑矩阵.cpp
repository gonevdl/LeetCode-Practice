#include<iostream>
#include<vector>
using namespace std;

/*
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
示例 1：
输入：mat = [[1,2],[3,4]], r = 1, c = 4
输出：[[1,2,3,4]]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reshape-the-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        //存储最终结果
        vector<vector<int>> result;
        //存储一行数组
        vector<int> matRow = mat[0];
        //判断列数
        int row1 = matRow.size();
        //判断行数
        int row2 = mat.size();
        //判断是否可以相互转化
        if ((r * c) == (row1 * row2)) {
            //存储每一行临时数据
            vector<int> temp;
            int count = 1;
            //读取原来矩阵中的每一个元素
            for (vector<int> v : mat) {
                for (int i = 0; i < v.size(); i++) {
                    temp.push_back(v[i]);
                    if (count == c) {
                        result.push_back(temp);
                        temp.clear();
                        count = 0;
                    }
                    count++;
                }
            }
            return result;
        }
        else {
            return mat;
        }
    }
};
int main() {
    Solution S;
    vector<vector<int>> mat1 = { {1,2},{3,4} };
    int r1 = 1;
    int c1 = 4;
    vector<vector<int>> result1 = S.matrixReshape(mat1, r1, c1);
    vector<vector<int>> mat2 = { {1,2},{3,4},{5,6} };
    int r2 = 3;
    int c2 = 4;
    vector<vector<int>> result2 = S.matrixReshape(mat2, r2, c2);
    for (vector<int> v : result1) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    for (vector<int> v : result2) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
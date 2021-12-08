#include<iostream>
#include<vector>
using namespace std;

/*
给你一个 n * n 的网格 grid ，上面放置着一些 1 x 1 x 1 的正方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
放置好正方体后，任何直接相邻的正方体都会互相粘在一起，形成一些不规则的三维形体。
请你返回最终这些形体的总表面积。
注意：每个形体的底面也需要计入表面积中。
输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：32
*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0;
        if (grid.size() == 1) {
            return grid[0][0] * 6 - 2 * (grid[0][0] - 1);
        }
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (i == 0) {
                    if (j == 0) {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i + 1][j], grid[i][j]) - min(grid[i][j + 1], grid[i][j]);
                    }
                    else if (j == grid.size() - 1) {
                        result+= 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i][j - 1], grid[i][j]) - min(grid[i + 1][j], grid[i][j]);
                    }
                    else {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i][j - 1], grid[i][j]) - min(grid[i + 1][j], grid[i][j])
                            - min(grid[i][j + 1], grid[i][j]);
                    }
                }
                else if (i == grid.size() - 1) {
                    if (j == 0) {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i - 1][j], grid[i][j]) - min(grid[i][j + 1], grid[i][j]);
                    }
                    else if (j == grid.size() - 1) {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i][j - 1], grid[i][j]) - min(grid[i - 1][j], grid[i][j]);
                    }
                    else {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i][j - 1], grid[i][j]) - min(grid[i - 1][j], grid[i][j])
                            - min(grid[i][j + 1], grid[i][j]);
                    }
                }
                else {
                    if (j == 0) {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i - 1][j], grid[i][j]) - min(grid[i][j + 1], grid[i][j])
                            - min(grid[i + 1][j], grid[i][j]);
                    }
                    else if (j == grid.size() - 1) {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i][j - 1], grid[i][j]) - min(grid[i - 1][j], grid[i][j])
                            - min(grid[i + 1][j], grid[i][j]);
                    }
                    else {
                        result += 6 * grid[i][j] -
                            2 * (max(0, grid[i][j] - 1)) - min(grid[i][j - 1], grid[i][j]) - min(grid[i - 1][j], grid[i][j])
                            - min(grid[i][j + 1], grid[i][j]) - min(grid[i + 1][j], grid[i][j]);
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> grid = { {1,1,1},{1,0,1},{1,1,1} };
    Solution S;
    cout << S.surfaceArea(grid) << endl;
    return 0;
}
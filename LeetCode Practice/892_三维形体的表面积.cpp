#include<iostream>
#include<vector>
using namespace std;

/*
����һ�� n * n ������ grid �����������һЩ 1 x 1 x 1 �������塣
ÿ��ֵ v = grid[i][j] ��ʾ v ������������ڶ�Ӧ��Ԫ�� (i, j) �ϡ�
���ú���������κ�ֱ�����ڵ������嶼�ụ��ճ��һ���γ�һЩ���������ά���塣
���㷵��������Щ������ܱ������
ע�⣺ÿ������ĵ���Ҳ��Ҫ���������С�
���룺grid = [[1,1,1],[1,0,1],[1,1,1]]
�����32
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
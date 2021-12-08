#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
注意：
一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
示例 1：
输入：board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> temp;
        set<char> temp2;
        set<char> temp3;
        bool result = true;
        set<char>::iterator it;
        for (vector<char> row : board) {
            for (char symbol : row) {
                if (symbol != '.') {
                    it = temp.find(symbol);
                    if (it == temp.end()) {
                        temp.insert(symbol);
                    }
                    else {
                        result = false;
                        return result;
                    }
                }
            }
            temp.clear();
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char symbol = board[j][i];
                if (symbol != '.') {
                    it = temp.find(symbol);
                    if (it == temp.end()) {
                        temp.insert(symbol);
                    }
                    else {
                        result = false;
                        return result;
                    }
                }
            }
            temp.clear();
        }
        int i = 0;
        int j = 0;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                char symbol = board[i][j];
                if (symbol != '.') {
                    if (j >= 0 && j < 3) {
                        it = temp.find(symbol);
                        if (it == temp.end()) {
                            temp.insert(symbol);
                        }
                        else {
                            result = false;
                            return result;
                        }
                    }
                    else if (j >= 3 && j < 6) {
                        it = temp2.find(symbol);
                        if (it == temp2.end()) {
                            temp2.insert(symbol);
                        }
                        else {
                            result = false;
                            return result;
                        }
                    }
                    else {
                        it = temp3.find(symbol);
                        if (it == temp3.end()) {
                            temp3.insert(symbol);
                        }
                        else {
                            result = false;
                            return result;
                        }
                    }
                }
            }
            if ((i + 1) % 3 == 0) {
                temp.clear();
                temp2.clear();
                temp3.clear();
            }
        }
        return result;
    }
};

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& borad) {
        int row[9][10] = { 0 };
        int column[9][10] = { 0 };
        int box[9][10] = { 0 };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (borad[i][j] == '.') continue;
                int temp = borad[i][j] - '0';
                if (row[i][temp]) return false;
                if (column[j][temp]) return false;
                if (box[j / 3 + (i / 3) * 3][temp]) return false;
                row[i][temp] = 1;
                column[j][temp] = 1;
                box[j / 3 + (i / 3) * 3][temp] = 1;
            }
        }
        return true;
    }
};
int main() {
    Solution S;
    Solution1 S1;
    vector<vector<string>> board = { {"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."} ,
        {".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"} };
    vector<vector<char>> board1;
    vector<char> temp;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            temp.push_back(board[i][j][0]);
        }
        board1.push_back(temp);
        temp.clear();
    }
    cout << S1.isValidSudoku(board1) << endl;
}
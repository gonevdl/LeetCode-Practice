#include<iostream>
using namespace std;
/*
* 给你 二维 平面上两个 由直线构成的 矩形，请你计算并返回两个矩形覆盖的总面积。
每个矩形由其 左下 顶点和 右上 顶点坐标表示：
第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
输出：45
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //首先判断两个矩形是否有交叉
        //如果没有
        if (by1 > ay2 || bx1 > ax2 || by2 < ay1 || bx2 < ax1) {
            int s = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
            return s;
        }
        else {
            int temp = (min(ax2, bx2) - max(ax1, bx1)) * (min(by2, ay2) - max(ay1, by1));
            int s = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - temp;
            return s;
        }
    }
};
int main() {
    Solution S;
    int ax1 = -5;
    int ay1 = -5;
    int ax2 = 0;
    int ay2 = -4;
    int bx1 = -3;
    int by1 = -3;
    int bx2 = 3;
    int by2 = 3;
    cout << S.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
}
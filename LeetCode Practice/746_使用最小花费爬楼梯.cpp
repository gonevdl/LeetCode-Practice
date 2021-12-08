#include<iostream>
#include<vector>
using namespace std;
/*
数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
示例 1：
输入：cost = [10, 15, 20] 输出：15
解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
示例 2：
输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1] 输出：6
解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//totalCost[i]是在没有站上第i个台阶时的最小花费
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int totalCost1 = 0;
        int totalCost2 = 0;
        int totalCost = 0;
        if (cost.size() == 1) return cost[0];
        if (cost.size() == 2) return min(cost[0], cost[1]);
        for (int i = 2; i <= cost.size(); i++) {
            totalCost1 = totalCost2;
            totalCost2 = totalCost;
            totalCost = min((totalCost1 + cost[i - 2]), (totalCost2 + cost[i - 1]));
        }
        return totalCost;
    }
};

int main() {
    Solution S;
    vector<int> cost1 = { 10,15,20 };
    vector<int>cost2 = { 1,100,1,1,1,100,1,1,100,1 };
    cout << S.minCostClimbingStairs(cost1) << endl;
    cout << S.minCostClimbingStairs(cost2) << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

/*
*给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 
表示该线路将会从 cityAi 直接前往 cityBi 。
请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。
题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。
输入：paths = [["B","C"],["D","B"],["C","A"]]
输出："A"
解释：所有可能的线路是：
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
显然，旅行终点站是 "A" 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/destination-city
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> temp;
        for (vector<vector<string>>::iterator it1 = paths.begin(); it1 != paths.end(); it1++) {
            bool flag = false;
            for (vector<vector<string>>::iterator it2 = paths.begin(); it2 != paths.end(); it2++) {
                if ((*it1)[1] == (*it2)[0]) {
                    flag = true;
                    //temp = *it1;
                    break;
                }
            }
            if (flag == false) {
                temp = *it1;
                break;
            }
        }
        return temp[1];
    }
};

int main() {
    Solution s;
    vector<string> v1 = { "B","C" };
    vector<string> v2 = { "D","B" };
    vector<string> v3 = { "C","A" };
    vector<vector<string>> paths;
    paths.push_back(v1);
    paths.push_back(v2);
    paths.push_back(v3);

    string result = s.destCity(paths);
    cout << "旅行终点站是" << result << endl;
}
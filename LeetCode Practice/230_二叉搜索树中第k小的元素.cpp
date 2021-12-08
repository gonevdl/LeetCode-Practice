#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        putInVector(root);
        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
    void putInVector(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        putInVector(root->left);
        putInVector(root->right);
    }
private:
    vector<int> nums;
};
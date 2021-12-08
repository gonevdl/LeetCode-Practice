#include<iostream>
#include<vector>
using namespace std;

/*
给你二叉树的根节点 root ，返回它节点值的 后序 遍历。
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            this->postorderTraversal(root->left);
            this->postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
    }

private:
    vector<int> result;
};

int main() {
    Solution S;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = nullptr;
    root->left->left->left = root->left->left->right = nullptr;
    root->right->left = new TreeNode(4);
    root->right->right = nullptr;
    root->right->left->left = nullptr;
    root->right->left->right = new TreeNode(6);
    root->right->left->right->left = root->right->left->right->right = nullptr;
    vector<int> result;
    result = S.postorderTraversal(root);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
#include<iostream>
#include<queue>
using namespace std;
/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
*/

//层序遍历一般使用队列，将每一层的结点放入队列，然后在弹出这个结点之前，将节点的左右孩子分别在写入队列。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> level;
        vector<int> temp = {};
        vector<vector<int>> result = {};
        level.push(root);
        while (!level.empty()) {
            queue<TreeNode*> tmp;
            while (!level.empty()) {
                temp.push_back(level.front()->val);
                if (level.front()->left != nullptr) {
                    tmp.push(level.front()->left);
                }
                if (level.front()->right != nullptr) {
                    tmp.push(level.front()->right);
                }
                level.pop();
            }
            level = tmp;
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
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
    vector<vector<int>> result;
    result = S.levelOrder(root);
    for (vector<int> v : result) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
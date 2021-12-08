#include<iostream>
using namespace std;

/*
翻转一棵二叉树。
示例：输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        //if (root->left && !root->right) {
        //    root->right = new TreeNode(root->left->val);
        //    //delete root->left;
        //    root->left = nullptr;
        //    return root;
        //}
        //if (!root->left && root->right) {
        //    root->left = new TreeNode(root->right->val);
        //    //delete root->right;
        //    root->right = nullptr;
        //    return root;
        //}
        this->Swap(root->left, root->right);
        return root;
    }
    void Swap(TreeNode* &p, TreeNode* &q) {
        if (p == nullptr && q == nullptr) return;
        if (p == nullptr && q != nullptr) {
            p = q;
            //delete q;
            q = nullptr;
            Swap(p->left, p->right);
            return;
            //Swap(p->right, q->left);
        }
        if (p != nullptr && q == nullptr) {
            q = p;
            //delete p;
            p = nullptr;
            Swap(q->left, q->right);
            //Swap(p->right, q->left);
            return;
        }
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        Swap(p->left, q->right);
        Swap(p->right, q->left);
    }

    void Print(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->val << " ";
        Print(root->left);
        Print(root->right);
    }
};

int main() {
    Solution S;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(7);
    root->right = nullptr;
    //root->left->left = new TreeNode(1);
    //root->left->right = new TreeNode(3);
    //root->right->left = new TreeNode(6);
    ////root->right->right = new TreeNode(9);
    //root->right->right = nullptr;
    S.Print(root);
    root = S.invertTree(root);
    S.Print(root);
}
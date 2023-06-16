/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    queue<TreeNode*> q;
    TreeNode* increasingBST(TreeNode* root) {
        fun(root);
        TreeNode* cur = q.front();
        cur->left = nullptr;
        q.pop();
        TreeNode* res = cur;
        while (!q.empty()) 
        {
            cur->right = q.front();
            cur->left = nullptr;
            cur = cur->right;
            q.pop();
        }
        cur->right = nullptr;
        cur->left = nullptr;
        return res;
    }
    void fun(TreeNode* root) {
        if (root != nullptr){
            fun(root->left);
            q.push(root);
            fun(root->right);
        }
    }
}; 
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
    TreeNode* ans;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        fun(root, val);
        return ans;
    }
    void fun(TreeNode* root, int val){
        if(root == nullptr)return;
        if(root->val == val){
            ans = root;
            return;
        }
        fun(root->left, val); 
        fun(root->right, val); 
    }
};
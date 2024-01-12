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
        int diff = 0;
        void dfs(TreeNode* root, int mn, int mx){
                if(root==nullptr)return;
                diff = max(diff, max(abs(root->val - mn), abs(root->val - mx)));
                mn = min(mn, root->val);
                mx = max(mx, root->val);
                dfs(root->left, mn, mx);
                dfs(root->right, mn, mx);
        }
    int maxAncestorDiff(TreeNode* root) {
        int mn = root->val, mx = root->val;
            dfs(root, mn, mx);
            return diff;
    }
};
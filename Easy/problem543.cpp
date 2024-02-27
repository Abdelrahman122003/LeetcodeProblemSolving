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
        int ans = 0;
 int fun(TreeNode* root){
          if(root == NULL )return 0;
          int l = fun(root->left), r = fun(root->right);
          ans = max(ans , l+r);
          return 1 + max(l, r);
  }
    int diameterOfBinaryTree(TreeNode* root) {
        // inorder -> LVR
        // posorder -> LRV
        // preorder -> VLR
        fun(root);
        return ans;
    }
        
 
};
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
  // ans = 
public:
    bool evaluateTree(TreeNode* root) {
        // inorder -> LVR
        // posorder -> LRV --> solution need this traverse
        // preorder -> VLR
        if(root == nullptr){
          return root->val;
        }
        if(root->val == 2){
          return(evaluateTree(root->left) | evaluateTree(root->right));
        }
        if(root->val == 3){
          return(evaluateTree(root->left) & evaluateTree(root->right));
        }
        return root->val;
    }
};
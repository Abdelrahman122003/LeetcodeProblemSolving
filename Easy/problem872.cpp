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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1, v2;
        traverse(v1, root1);
        traverse(v2, root2);
        return(v1==v2);
    }
    void traverse(vector<int>&v1, TreeNode* node){
      if(node == nullptr)return;
      if(node->left == nullptr && node->right == nullptr){
        v1.push_back(node->val);
      }
      traverse(v1, node->left);
      traverse(v1, node->right);
    }
};
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
    int count = 0;
    int goodNodes(TreeNode* root) {
      if(root==NULL)return 0;
      traverse(root, root->val);
      return count;
    }
    void traverse(TreeNode* root, int mx){
      if(root == nullptr)return;
      if(root->val >= mx){
      cout << root->val << endl;
        mx = root->val;
        count++;
      }
      traverse(root->left, mx);
      traverse(root->right, mx);
    }
  };

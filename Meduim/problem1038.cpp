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
    vector<pair<int, int>>v;  
       map<int, int>m;
//         traverse to update values
    void updateTree(TreeNode *root){
             if(root == nullptr)return;
            updateTree(root->left);
            root->val = m[root->val]; 
            updateTree(root->right);
    }
    void traversal(TreeNode* root){
        // In-order traversal results in values sorted from left to right, allowing you to determine which values are greater than a specified reference
            if(root == nullptr)return;
            traversal(root->left);
            v.push_back({root->val, root->val});
            traversal(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        traversal(root);
             
         for(int i = v.size()-2;i >= 0;i--)
                 v[i].second += v[i+1].second;
           for(auto [k, v] : v)
                   m[k] = v;
          updateTree(root);
          return root;
    }
};
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
    int maxDep(TreeNode* root){
            if(!root)return 0;
            int l = maxDep(root->left);
            int r = maxDep(root->right);
            return max(l+1, r+1);
    }
    int deepestLeavesSum(TreeNode* root) {
            int maxL = maxDep(root);
        queue<TreeNode*>q;
         q.push(root);
         int level = 1;
         while(level != maxL){
                 int size = q.size();
                 while(size--){
                         TreeNode* top =q.front();
                                 q.pop(); 
                         if(top->left)
                                 q.push(top->left);
                         if(top->right)
                                 q.push(top->right);
                                
                 }
                 level++;
         }
            int sum = 0;
         while(!q.empty())
                 sum += q.front()->val, q.pop();
            
            return sum;
    }
};
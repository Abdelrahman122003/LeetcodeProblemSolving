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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int sum = root->val, minL = 1, level = 1;
        q.push(root);
            while(!q.empty()){
                    int sumForL = 0;
                    int size = q.size();
                    while(size--){
                            TreeNode *top = q.front();
                            q.pop();
                            sumForL += top->val;
                            if(top->left)
                                    q.push(top->left);
                            if(top->right)
                                    q.push(top->right);
                    }
                     if(sum < sumForL)
                            minL = level, sum = sumForL;
                    level++;
              }
            
            return minL;
    }
};
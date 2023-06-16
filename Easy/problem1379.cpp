/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* res;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        fun(cloned, target);
        return(res);
    }
    void fun(TreeNode* cloned, TreeNode* target){
        if(cloned == nullptr){
            return;
        }
        else if(cloned->val == target->val){
            res = cloned;
            return;
        }
        fun(cloned->left,target);
        fun(cloned->right,target);
    }
};
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        checK(root, sum, false);
        return(sum);
    }
    void checK(TreeNode* root,int &sum,bool f){
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr && f){
            sum += root->val;
        }
        checK(root->left, sum, true);
        checK(root->right, sum, false);
        // return sum;
    }
};
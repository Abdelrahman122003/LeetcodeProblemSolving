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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // if (root1 == nullptr && root2 == nullptr) {
        //     return nullptr;
        // }
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        TreeNode* n = new TreeNode(root1->val + root2->val);
        n->left = mergeTrees(root1->left, root2->left);
        n->right = mergeTrees(root1->right, root2->right);
        return n;
    }
};


    // void fun(TreeNode* root1, TreeNode* root2, f)
    // {
    //     if(root1 == nullptr && root2 == nullptr)return;
    //     if(root1 != nullptr && root2 != nullptr && !f){
    //         root1-val +=root2->val; 
    //     }
    //     fun(root1->left, false);
    //     fun(root2->left, false);
    //     fun(root1->right, true);
    //     fun(root2->right, true);
    // }

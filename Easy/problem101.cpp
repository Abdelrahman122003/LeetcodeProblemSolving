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
    bool isSymmetric(TreeNode* root) {
       return(checkEqual(root, root));   
    }
    bool checkEqual(TreeNode* n1, TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr)return true;
        else if((n1 == nullptr && n2 != nullptr) || (n1 != nullptr && n2==nullptr))return false;
        else 
            return (n1->val == n2->val) && (checkEqual(n1->left, n2->right)) &&
            (checkEqual(n1->right, n2->left));
    }
};

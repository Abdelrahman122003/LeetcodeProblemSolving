class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
//           base case 
            if(!root)
                return nullptr;
//             go to left 
             root->left = removeLeafNodes(root->left, target);
//             go to right 
            root->right =  removeLeafNodes(root->right, target);
//             check if leaf is equal to target return nullptr if yes
            if(!root->left && !root->right && root->val == target)
                return nullptr;
                    
            return root;
    }
    
};
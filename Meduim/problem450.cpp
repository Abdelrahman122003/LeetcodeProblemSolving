class Solution {
public:
    int getSuc(TreeNode* node) {
        if (!node->left) return node->val;
        return getSuc(node->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
        {
            if(root == NULL) return NULL;

            if(key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else if(key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else
            {
                // Key found
                // Either both child don't exist or left child don't exist
                if(root->left == NULL)
                    return root->right;
                    
                // right child don't exist
                else if(root->right == NULL)
                    return  root->left;
                
                // Both children are present
                else
                {
                    int replace = getSuc(root->right);
                    root->val = replace;
                    root->right = deleteNode(root->right, replace);
                }
            }

            return root;
        }
};
        
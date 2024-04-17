class Solution {
public:
        string str;
    string smallestFromLeaf(TreeNode* root, string cur = "") {
            //normally people return "" which in this case is wrong because we are using minimum to find result and tilda(~) is just infinity for string, We return this so that whenever we ncounter any null we just return infinity, that way when we find minimum we don't mess up our result.
          if(!root)
                   return "~";
// Receive the answer when we are about to leave.
           if(!root->left && !root->right)
                   return char(root->val + 'a') + cur;
//             to minmize answer
           return min(smallestFromLeaf(root->left, char(root->val + 'a') + cur), 
           smallestFromLeaf(root->right, char(root->val + 'a') + cur));
    }
};
   
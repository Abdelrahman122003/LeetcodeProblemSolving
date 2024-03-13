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

// ** explaintion
// first approach:
// 1)mplementtwo depth-first searches (DFS) to calculate the number of paths that equal a target sum. The first DFS iterates through each node (subtree), while the second DFS starts from each of these nodes (as root) to compute the paths
class Solution {
public:
        int count = 0;
        int calculatePaths(TreeNode*root, long long tar){
                if(!root)return 0;
                int counter = 0;
                if(tar == root->val)counter = 1;
                
// This statement proposes subtracting the current node's value from the target sum to ascertain if the remaining value of targetsum equals the current node's value
               tar -= root->val;
                
                counter += calculatePaths(root->left, tar);
                counter += calculatePaths(root->right, tar);
                
                return counter;
        }
    int pathSum(TreeNode* root, int tar) {
         if(!root)return 0;   
            count  += calculatePaths(root, tar);
            pathSum(root->left, tar);
            pathSum(root->right, tar);
            
            return count;
    }
};
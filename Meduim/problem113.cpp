class Solution {
public:
    vector<vector<int>>ans;
//    backtrack solution
    void dfs(TreeNode *root,int targetsum,int sum,vector<int>&v){
            if(root == nullptr)return;
            if(sum == targetsum && !root->left && !root->right)
                 ans.push_back(v);
                    
            if(root->left){
                    v.push_back(root->left->val);
                    dfs(root->left, targetsum, sum+root->left->val, v);
                    v.pop_back();
            }
            
            if(root->right){
                v.push_back(root->right->val);
                dfs(root->right, targetsum,sum+root->right->val, v);
                v.pop_back();
            }
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            if(!root)return ans;
         vector<int>v;
            v.push_back(root->val);
         dfs(root, targetSum,root->val, v);
            return ans;
    }
};  
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
        vector<int>adj[100005];
        int dep[100005];
        void convertToGraph(TreeNode* root){
                if(root->left){
                        adj[root->left->val].push_back(root->val);
                        adj[root->val].push_back(root->left->val);
                        convertToGraph(root->left);
                }
                if(root->right){
                        adj[root->right->val].push_back(root->val);
                        adj[root->val].push_back(root->right->val);
                        convertToGraph(root->right);
                }
                
        }
        void dfs(int node,int p){
                for(auto v : adj[node]){
                        if(v != p){
                                dfs(v, node);
                                dep[node] = max(dep[node], dep[v]+1);
                        }
                }
                
        }
    int amountOfTime(TreeNode* root, int start) {
        convertToGraph(root);
            dfs(start, 0);
            return dep[start];
    }
};
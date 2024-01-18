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
public:
    vector<int>adj[10000];
        map<int, bool>m;
        void convertToGraph(TreeNode* root){
                if(root->left){
                        adj[root->left->val].push_back(root->val);
                        adj[root->val].push_back(root->left->val);
                        m[root->left->val] = true, m[root->val] = true;
                        convertToGraph(root->left);
                }
                 if(root->right){
                        adj[root->right->val].push_back(root->val);
                        adj[root->val].push_back(root->right->val);
                          m[root->right->val] = true, m[root->val] = true;
                        convertToGraph(root->right);
                }
        }
        void bfs(int node, vector<int>&dis){
                queue<int>q;
                q.push(node);
                int level = 0;
                while(!q.empty()){
                        int si = q.size();
                        while(si--){
                                int t = q.front();
                                q.pop();
                                 dis[t] = level;
                                for(auto n : adj[t]){
                                        if(dis[n] == 1e6)
                                               q.push(n);
                                }
                        }
                        level++;
                }
        }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            vector<int>dis(500, 1e6);
            for(auto i : dis)
                    i = 1e6;
        convertToGraph(root);
            bfs(target->val, dis);
            vector<int>ans;
            cout << target->val << endl;
            for(auto [key, value] : m){
                    if(dis[key]== k)
                            ans.push_back(key);
                    
            }
            return ans;
    }
};
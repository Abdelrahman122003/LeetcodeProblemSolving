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
// 1) first approach ---> use map for construction
class Solution {
public:
    unordered_set<int>children;
    unordered_map<int, TreeNode*>tree;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
            for(auto des: descriptions){
                    int parent = des[0]; 
                    int child = des[1]; 
                    int isLeft = des[2]; 
                    if(!tree.count(parent))
                            tree[parent] = new TreeNode(parent);
                    if(!tree.count(child))
                            tree[child] = new TreeNode(child);
                    
                    if(isLeft)
                            tree[parent]->left = tree[child];
                    else
                            tree[parent]->right = tree[child];
                    children.insert(child);
            }
            for(auto [k, v] : tree){
                    if(children.find(k) == children.end())
                            return tree[k];
            }
           return nullptr;
    }
};
// 2) second approach ---> use bfs construction
class Solution {
public:
        unordered_map<int, bool>m;
        unordered_map<int, pair<int, int>>adj;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
            // 1) Get an efficient way to store the descriptions
            for(auto k : descriptions){
                    if(!m[k[0]])
                            m[k[0]] = false;
                    if(k[2])
                            adj[k[0]].first = k[1];
                    else 
                            adj[k[0]].second = k[1];
                    m[k[1]] = true;
            }
            // 2) Determine which is the root
            int rootVal = -1;
            for(auto [k, v] : m)
                    if(!v)
                            rootVal = k;
            queue<TreeNode*>q;
            TreeNode* root = new TreeNode(rootVal);
            q.push(root);
            // 3) Construct a tree using BFS
            while(!q.empty()){
                    TreeNode* parent = q.front();
                    q.pop();
                    TreeNode* leftChild =   new TreeNode(adj[parent->val].first);
                    TreeNode* rightChild =   new TreeNode(adj[parent->val].second);
                    if(leftChild->val)
                            parent->left = leftChild, q.push(leftChild);
                    if(rightChild->val)
                            parent->right = rightChild, q.push(rightChild);
            }
            return root;
    }
};
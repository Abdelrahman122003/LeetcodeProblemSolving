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
// This is not correct because duplicates will occur. We have 100 values for nodes, but the number of nodes will reach 1024.
    unordered_map<TreeNode* , vector<TreeNode*>>adj;
    unordered_set<TreeNode*>leaves;
// Function to convert the tree into a graph, so that BFS can be performed on it.
    void convertTreeIntoGraph(TreeNode *root){
            if(!root)
                    return;
            if(!root->left && !root->right)
                    leaves.insert(root);
            if(root->right){
                    adj[root->right].push_back(root);
                    adj[root].push_back(root->right);
            }
            if(root->left){
                    adj[root->left].push_back(root);
                    adj[root].push_back(root->left);
            }
            convertTreeIntoGraph(root->left);
            convertTreeIntoGraph(root->right);
    }
// This BFS function traverses the graph level by level to get the distance. 
// If the level is less than or equal to the given distance and the node is a leaf, 
// the leaf node counter is increased by 1.
    int Bfs(TreeNode* node, int distance){
          queue<pair<TreeNode*, int>>q;
          q.push({node, 0});
          unordered_set<TreeNode*>visit;
          visit.insert(node);
          int counter = 0;
           
           while(!q.empty()){
                TreeNode* currNode = q.front().first;
                int dist = q.front().second;
                 q.pop();
                if(node != currNode && dist <= distance && leaves.count(currNode))
                        counter++;
                for(auto k : adj[currNode])
                        if(!visit.count(k) && dist < distance)
                                q.push({k, dist+1}), visit.insert(k);
           }
           return counter;
    }
    
    int countPairs(TreeNode* root, int distance) {
            int ans = 0;
            convertTreeIntoGraph(root);
            for(auto node : leaves)
                ans += Bfs(node, distance);
            return ans/2;
    }
};

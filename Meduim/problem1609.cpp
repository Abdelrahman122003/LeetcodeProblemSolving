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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
         TreeNode* current = root;
        q.push(current);
        if(root->val%2 == 0)return false;
        int level = 1;
         while(q.size() != 0){
                 if(level >= 4){
                         cout << q.size() << endl;
                 }
                  deque<long>v;
                 int size = q.size();
                 while(size--){
                         current = q.front();
                         q.pop();
                         if(current->left != nullptr) 
                              q.push(current->left), v.push_back(current->left->val);
                               
                          if(current->right != nullptr) 
                               q.push(current->right), v.push_back(current->right->val);
                 }
//                  fuckkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
                 if(v.empty())break;
                 if(level%2){
                        if(v[0]%2)return false;
                         for(int i = 1;i < v.size(); i++)
                                 if(v[i] >= v[i-1] || v[i]%2)
                                         return false;
                 }else{
                        if(v[0]%2 == 0)return false;
                        for(int i = 1;i < v.size(); i++)
                                 if(v[i] <= v[i-1] || v[i]%2 == 0)
                                         return false;
                         
                 }
                 level++;
         }
        return true;
    }
};
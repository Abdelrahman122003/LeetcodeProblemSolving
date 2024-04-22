class Solution {
public:
    vector<int>ans;
    vector<int> rightSideView(TreeNode* root) {
            if(!root) return {};
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                    int size = q.size();
                    while(size--){
                            TreeNode* top = q.front();
                            q.pop();
                            if(!size)
                                    ans.push_back(top->val);
                            if(top->left)
                                   q.push(top->left);
                            if(top->right)
                                   q.push(top->right);
                            
                    }
            }
        return ans;
    }
};
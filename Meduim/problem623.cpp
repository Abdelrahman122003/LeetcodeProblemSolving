class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
                TreeNode* newTree = new TreeNode(val);
                newTree->left = root;
                return newTree;
        }
            int l = 1;
            queue<TreeNode*>q;
            q.push(root);
            depth--;
            while(l < depth){
                    int size = q.size();
                    while(size--)
                    {
                          TreeNode* top = q.front();
                            q.pop();
                            if(top->left)
                                    q.push(top->left);
                            if(top->right)
                                    q.push(top->right);
                          
                    }
                    l++;
            }
            while(!q.empty())
            {
                   TreeNode* newLeft = new TreeNode(val); 
                   TreeNode* newRight = new TreeNode(val);
                   TreeNode* top = q.front();
                    q.pop();
                    newLeft->left = top->left;
                    newRight->right = top->right;
                    top->left = newLeft;
                    top->right = newRight;
                    
            }
            return root;
    }
};
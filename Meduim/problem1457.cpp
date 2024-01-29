class Solution {
public:
        int v[10];
        int count = 0;
    void ch(){
            int odd = 0;
            for(int i = 1;i < 10;i++)
                    if(v[i]%2)odd++;
            if(odd<=1)count++;
    }
   void solve(TreeNode* root){
            if(root == NULL)return;
            v[root->val]++;
            if(root->left==NULL && root->right == NULL)
                    ch();
           else{
                   solve(root->left);
                   solve(root->right);
           }
           v[root->val]--;
          
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
         return count;
    }
  
};
class Solution {
public:
    int res;
        string str;
     //   solution 1:  
    int sumNumbers(TreeNode* root) {
        res = 0;
            str = "";
            fun(root);
           return res;
    }
        void fun(TreeNode* root){
                if(root == nullptr)
                        return ;
                if(root->left == nullptr && root->right == nullptr)
                      { 
                        str += to_string(root->val), res += stoi(str), str.pop_back();
                        return;
                      }
//              call left 
//                 peek
                str+= to_string(root->val);fun(root->left);
//                 leave
                str.pop_back();
//              call right 
//                 peek
               str+= to_string(root->val);fun(root->right);
//                 leave
                str.pop_back();
        }


 
//       solution 2
    //  int sumNumbers(TreeNode* root, int res = 0) {
    //     if(!root)
    //             return 0;
    //     res = res*10 + root->val;
    //     if(!root->left && !root->right)
    //             return res;
    //     return sumNumbers(root->left, res) + sumNumbers(root->right, res);
    // }
};
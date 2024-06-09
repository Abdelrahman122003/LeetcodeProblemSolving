//   First Approach ->> binary search solution
// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         sort(products.begin(), products.end());
//             vector<vector<string>>ans;
//             for(int i = 0;i < searchWord.size();i++){
//                 string currS = searchWord.substr(0, i+1);
//                 int startP = lower_bound(products.begin(), products.end(), currS) - products.begin();
//                 vector<string>ansPerS;
//                 for(int j = startP; j < products.size() && j < startP + 3 && !products[j].compare(0, currS.size(), currS);j++)
//                     ansPerS.push_back(products[j]);
//                 ans.push_back(ansPerS);
//         }
//             return ans;
//     }
// };


// Second Approach ->> Trie


class Trie {
        private:
        struct Node{
                // static const int MAX_INT = 26
                bool isWord{false};
                vector<Node*>child{vector<Node*>(26, NULL)};
        } *Root, *curr;
        // Runs a DFS on trie starting with given prefix and adds all the words in the result, limiting result size to 3
        void dfsWithPrefix(Node *curr, vector<string>& res, string &word){
                if(res.size() == 3)
                        return;
                if(curr->isWord)
                        res.push_back(word);
                for(char i = 'a'; i <= 'z';i++){
                        if(curr -> child[i - 'a']){
//                                 peek
                                word+=i;
                                dfsWithPrefix(curr->child[i-'a'], res, word);
//                                 leave
                                word.pop_back();
                        }
                }
        }
        
        public:
        Trie(){
               Root = new Node();
        }
        
        
//         insert 
          void insert(string word){
                    // Points curr to the root of trie.
                  curr = Root;
                  for(auto c : word){
                          if(!curr->child[c-'a']) 
                                  curr->child[c-'a'] = new Node();
                        curr = curr->child[c-'a'];
                }
                  // Mark this node as a completed word.
                  curr->isWord = true;
          }
//         get first 3 smallest word with prefix
        vector<string> getWordsWithPrefix(string prefix){
                vector<string>res;
                curr = Root;
                for(auto c: prefix){
                        if(!curr->child[c - 'a'])
                                return res;
                        else 
                                curr = curr->child[c - 'a'];
                }
                dfsWithPrefix(curr, res, prefix);
                return res;
        }
};

class Solution {
        public : 
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
        {
            Trie trie = Trie();
                
        // Add all words to trie.
                for(auto k : products)
                        trie.insert(k);
                vector<vector<string>>ans;
                string prefix;
                for(auto c : searchWord){
                       prefix += c;
                        ans.push_back(trie.getWordsWithPrefix(prefix));
                }
                return ans;
        }
};
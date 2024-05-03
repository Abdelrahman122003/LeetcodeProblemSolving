class Trie {

        public:
        static const int MAX_CHAR = 26;  
         Trie *child[MAX_CHAR]; 
         bool isLeaf{false};
    Trie() {
        memset(child, 0, sizeof(child));
    }
    void insert(string word, int index = 0) {
        if(index == word.size())
                isLeaf = true;
            
         else {
                 int cur = word[index] - 'a';
                 if(!child[cur])
                         child[cur] = new Trie();
                 child[cur]->insert(word, index+1);
         }
    }
    
    bool search(string word, int index = 0) {
        if(index == word.size())
                return isLeaf;
            
            else{
                    int cur = word[index] - 'a';
                    if(!child[cur])
                            return false;
                    return child[cur]->search(word, index+1);
            }
    }
    
    bool startsWith(string prefix, int index = 0) {
        if(index == (int)prefix.size())
                return true;
            
            else{
                    int cur = prefix[index] - 'a';
                    if(!child[cur])
                            return false;
                    return child[cur]->startsWith(prefix, index+1);
            }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// Let's take an example to see how this code works.

// wordDict = ["cat","cats","and","sand","dog"]
// wordSearch = "catsanddog"
// At the beginning, we will start from index zero of wordSearch.


// For each node from these nodes, we will take a word from wordDict when it is suitable for wordSearch.

// 1- iterate overall words in wordDic 
// 2- we will search first word that suitable for wordSearch
// 3- Initially, check if the current word in the iteration is a substring of wordSearch by using the PossibilityOfTakingWord(0, current_word = cat) method.
// 4 -this method return true so go to new j = j + size(current_word) => j = 3
// 5- then call function again and repeat step 1, 2, 3


// Let's show the decision tree
                          

//                       root
//                  /           \
//                cat             cats 
//             /                     \
//           sand                    and  
//           /                         \
//          dog                        dog
class Solution {
public:
        
        vector<vector<string>>ans;
        vector<string>path, wordD;
        int n, nForWord;
        string w;
        bool PossibilityOfTakingWord(int start, string currentWord){
                if(currentWord.size() > nForWord - start)
                        return false;
                for(int i = 0; i < currentWord.size();i++)
                        if(w[start++] != currentWord[i])
                                return false;
                return true;
        }
    vector<string> wordBreak(string word, vector<string>& wordDict) {
        n = wordDict.size(), nForWord = word.size();
            w = word;
            wordD = wordDict;
               
            backtrack(0);
            vector<string>anss;
            for(int i = 0 ; i < ans.size();i++){
                    string str = "";
                    for(int j = 0; j < ans[i].size()-1; j++)
                            str += ans[i][j] + " ";
                    str += ans[i].back();
                    anss.push_back(str);
            }
            return anss;
    }
        void backtrack(int j){
//               base case
                if(j >= nForWord)
                {
                        ans.push_back(path);
                        return ;
                }
                for(auto k : wordD){
                         if(PossibilityOfTakingWord(j, k)){
                                path.push_back(k);
                                backtrack(j + k.size());
                                path.pop_back();
                        }
                }
        }
};




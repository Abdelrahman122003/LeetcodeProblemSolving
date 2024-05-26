class Solution {
public:
        vector<int>freqLetter, score;
        vector<string>w;
        int n, mxScore, mxPath;
        bool possibilityTakingWord(string str){
                vector<int>m(26);
                for(auto k : str)
                        m[k-'a']++;
                for(int i = 0;i < 26;i++)
                        if(freqLetter[i] < m[i])
                                return false;
                return true;
                
        } 
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& s) {
        
            n = words.size();
            w = words;
            score = freqLetter = vector<int>(26);
            score = s;
            for(auto l : letters)
                    freqLetter[l - 'a']++;
            mxScore = 0, mxPath = 0;
            backtrack(0);
            return mxScore;
    }
        void backtrack(int i){
                if(i >= n)
                {
                        mxScore = max(mxScore, mxPath);
                        return;
                }
//               1- Possibility of taking the current word or not
                if(possibilityTakingWord(w[i]))
                {
                        //2-  (peek)For every letter in current word, subtract one from freqLetter
                        for(auto l : w[i])
                                freqLetter[l-'a']--, mxPath+=score[l-'a'];
                        //3- call for next word                     
                        backtrack(i+1);
                        //4-  (leave)For every letter in current word, add one from freqLetter
                        for(auto l : w[i])
                                freqLetter[l-'a']++, mxPath-=score[l-'a'];
                }
//               5- skip(go to next word without take it)
                 backtrack(i+1);
        }
};
   
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
            for(;i < word.size();i++)
                if(word[i] == ch)
                        break;
            if(i < word.size())reverse(word.begin(), word.begin()+i+1);
            return word;
    }
};
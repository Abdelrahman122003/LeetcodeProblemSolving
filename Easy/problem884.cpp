// First Solution 
// class Solution {
// public:
//     unordered_map<string, int>m;
//     void extractWords(string text){
//         string word = "";
//         int size = text.size();
//         for(int i = 0;i < size;i++){
//             if(text[i] == ' ')
//                 m[word]++, word = "";
//             else
//                 word += text[i];
//         }
//         if(word != "")
//             m[word]++;
//     }
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         vector<string>ans;
//         extractWords(s1);
//         extractWords(s2);
//         for(auto [k, v] : m)
//             if(v == 1)
//                 ans.push_back(k);
//         return ans;
//     }
// };

// Second Solution
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>m;
        vector<string>ans;
        stringstream ss1(s1), ss2(s2);
        string word;
        while(ss1 >> word)
            m[word]++;
        while(ss2 >> word)
            m[word]++;
        
        for(auto [k, v] : m)
            if(v == 1)
                ans.push_back(k);
        return ans;
    }
};

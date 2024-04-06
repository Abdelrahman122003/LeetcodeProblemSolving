class Solution {
public:
        string d;
        vector<string>ans;
        string temp;
         map<char , string > m{{'2', "abc"},
                                 {'3', "def"}
                                ,{'4', "ghi"},
                                 {'5', "jkl"},
                                 {'6', "mno"},
                                 {'7', "pqrs"},
                                 {'8', "tuv"},
                                 {'9', "wxyz"}};
    vector<string> letterCombinations(string digits) {
            
            if(digits.size() == 0)return ans;
            d = digits;
            temp = "";
            solve(0);
            return ans;
    }
        
        
        void solve(int ind){
                
//                 base case ---> size string must be equal to size of input digits
                if(temp.size() == d.size()){
                        ans.push_back(temp);
                        return;
                }
//                 get string for current digit 
                string digit = m[d[ind]];
                for(int j = 0;j < digit.size();j++){
//                 peek
                                temp += digit[j];
                                solve(ind+1);
//                 leave
                                temp.pop_back();
                }
        }
};
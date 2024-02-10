class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>allAns;
            string ans = ""; 
            for(int i = 1 ;i < 10;i++){
                    ans = i+'0';
                    for(int j = i+1; j < 10;j++){
                           ans += j+'0';
                            if(stoll(ans) > high)break;
                           if(low <= stoll(ans) && high >= stoll(ans))
                                   allAns.push_back(stoll(ans));
                    }
            }
            sort(allAns.begin(), allAns.end());
            return allAns;
    }
};
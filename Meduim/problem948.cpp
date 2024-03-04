class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        sort(t.begin(), t.end());
        int i = 0, score = 0, c =t.size(),mx = 0;
        while(c--){
                if(power >= t[i])
                {
                        score++;
                        power -= t[i++];
                        mx = max(mx, score);
                }else if(score > 0){
                        score--;
                        power += t.back();
                        t.pop_back();
                        
                }else
                        break;
        }
            return mx;
    }
};
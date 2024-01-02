class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ios_base::sync_with_stdio(false); 
        cin.tie(nullptr);                 
        cout.tie(nullptr);
        long long total = 0, ans = 0, n = colors.size(), counter = 0, mx = -1;
        char cur = colors.front();
        total += neededTime.front();
        counter++;
        mx = neededTime.front();
        for(int i = 1;i < n;i++){
            if(cur == colors[i]){
                mx = max((long long)neededTime[i], mx);
                total += neededTime[i];
                counter++;
            }else{
                if(counter > 1){
                    ans += (total - mx);
                }
                total = neededTime[i];
                cur = colors[i];
                mx = total;
                counter = 1;
            }
        }
        if(counter > 1){
            ans += (total - mx);
        }
        return ans;
    }
};
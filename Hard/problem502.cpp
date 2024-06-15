class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>>v;
        for(int i = 0; i < n;i++)
                v.push_back({capital[i], profits[i]});
        sort(v.begin(), v.end());

        priority_queue<int>q;
        int i = 0, ans = w;
        while(k--){
//                For each instance of k, take all projects whose capital requirements are less than or equal to total capital.
                while(i < n && v[i].first <= ans)
                {
                        q.push(v[i++].second);	
                }
                if(q.empty())
                        break;
                // then take max between them => q.top()
                ans += q.top();
//                then delete it from queue
                q.pop();
        } 
        return ans;
    }
};
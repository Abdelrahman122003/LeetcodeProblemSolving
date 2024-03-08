class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        for(auto k : piles)
                q.push(k);
        while(k--){
                int top = q.top();
                q.pop();
                top =(top+1)/2;
                q.push(top);
        }
        int ans = 0;
          while(!q.empty())ans+=q.top(), q.pop();
            
            return ans;
    }
};
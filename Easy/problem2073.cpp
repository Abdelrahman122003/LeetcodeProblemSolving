class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        queue<int>q;
            int total = 0;
            for(int i = 0;i < t.size();i++)
                    q.push(i);
            while(!q.empty()){
                    total++;
                    int top = q.front();
                    q.pop();
                    t[top]--;
                    if(k == top && !t[top])
                            return total;
                    
                    if(t[top])
                            q.push(top);
                    
            }
            return 0;
    }
};
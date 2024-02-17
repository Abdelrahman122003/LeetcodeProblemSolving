class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int ans = 0, sum = 0;; 
        priority_queue<int, vector<int>, greater<int>>q; 
        for(int i = 1;i  < h.size();i++){
                int diff = h[i] - h[i-1];
                if(diff < 0)continue;
                q.push(diff);
                if(q.size() > l){
                        if(b >= q.top())b-=q.top(), q.pop();
                        else return i-1;
                }
        }
        
        return h.size()-1;
    }
};
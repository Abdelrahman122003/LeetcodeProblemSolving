class Solution {
public:
// first solution
long long totalCost(vector<int>& costs, int k, int candidates) {
   ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 
    cout.tie(nullptr);
    priority_queue<long long, vector<long long>, greater<long long>>left, right;
    long long i = 0;
    for(;i < candidates; i++){
        left.push(costs[i]);
    }
    long long j = costs.size()-1, co = 0;
    while(j >= i && co < candidates)
        right.push(costs[j]), j--, co++;
    long long ans = 0;
    while(k--){
      if (!left.empty() && !right.empty() &&  left.top() <= right.top()){
            ans += left.top();
            left.pop();
            if(j >= i)
                left.push(costs[i]), i++;
        }
        else if(!left.empty() && !right.empty() && left.top() >= right.top()){
            ans += right.top();
            right.pop();
            if(j >= i){
                right.push(costs[j]), j--;
            }
        } else if(left.empty()){
            ans += right.top();
            right.pop();
        }else if(right.empty()){
            ans += left.top();
            left.pop();
        }
    }
    return ans;
    }
    // second solution
     long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        
        long long ans = 0;
        
        int hired = 0;
        int i = 0;
        int j = n-1;
        
        while(hired < k){
            
            while(pq1.size() < candidates && i<=j) 
                pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) 
                pq2.push(costs[j--]);
            
            
            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;
            
            if(a <= b){
                ans += a;
                pq1.pop();
            } else {
                ans += b;
                pq2.pop();
            }
            
            hired++;
        }
        
        return ans;
    }
};
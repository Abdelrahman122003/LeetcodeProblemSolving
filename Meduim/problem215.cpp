class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>q;
        for (int i = 0; i < n; ++i){
          q.push(nums[i]);
        }
        int count = 1;
        int res = 0;
        while(!q.empty()) {
            if(count == k){
               res =  q.top();
               break;
            }else{
                q.pop();
            }
            count++;
        }
        return res;
    }
};
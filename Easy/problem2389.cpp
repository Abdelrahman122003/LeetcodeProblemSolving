class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    for (long long i = 1; i < nums.size(); i++)nums[i] += nums[i-1];
    long long k = 0;
    vector<int>res;
    for (long long i = 0; i < queries.size(); i++){
        long long  l = 0, r = nums.size() - 1; 
        int val = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] <= queries[k]){
                val = mid+1;
                l = mid+1;
            }else{
                r  = mid-1;
            }
        }
            res.push_back(val);
            k++;
        }
    return res;
    }
    
};
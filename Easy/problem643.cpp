class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
     long double res = LONG_LONG_MAX*-1;
    int l = 0, r = 0, count = 0;
    double sum = 0;
    while(r < nums.size()){
        while(count < k){
            sum += nums[r];
            r++;
            count++;
        }
        //cout << "details : " << count << " " << sum  << endl;
        if(count == k)res = max((long double)(sum/k), res);
        sum -= nums[l];
        l++;
        count--;
    }
        return res;
    }
};
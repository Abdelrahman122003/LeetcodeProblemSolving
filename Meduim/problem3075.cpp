class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
            long long sum = 0;
            for(int i = 0;i < k;i++)
                    if(happiness[i] - i > 0)
                            sum+=(happiness[i] - i);
            
            return sum;
    }
};
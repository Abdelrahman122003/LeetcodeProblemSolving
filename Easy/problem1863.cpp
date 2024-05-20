class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), total = 0;
            for(int i =  0; i < (1<<n);i++)
            {
                    bool f = false;
                    int sum = 0;
                    for(int j = 0 ;j < n;j++){
                            if(i & (1<<j)){
                                    if(!f)
                                            sum = nums[j], f = true;
                                    else
                                            sum ^= nums[j];
                            }
                    }
                    total +=sum;
            }
            return total;
    }
};
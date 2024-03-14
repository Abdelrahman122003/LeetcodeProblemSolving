class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
         vector<int>prefix(size+1, 0);
            unordered_map<int, int>m;
            for(int i = 1;i <= size ;i++)
                    prefix[i] = prefix[i-1] + nums[i-1], m[prefix[i]]++;
            
            
            int counter = 0;
            for(int i  = 1;i <= size ;i++)
            {
                    int tar = k + prefix[i-1];
                    if(m.count(tar) != 0)
                            counter += m[tar];
                    m[prefix[i]]--;
            }
            
            return counter;
    }
        
};
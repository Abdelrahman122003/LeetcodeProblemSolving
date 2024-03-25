class Solution {
public:
//         solution #1 
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>freqAns(nums.size()+1), ans;
            
//              [4,3,2,7,8,2,3,1]
//             indices [1, 2, 3, 4, 5, 6, 7, 8]
//             freq    [1, 2, 2, 1, 1, 1, 1, 1]
            for(auto k : nums)
                    freqAns[k]++;
            int j= 0;
            for(int i = 1;i < nums.size()+1;i++)
                    if(freqAns[i] > 1)
                            ans.push_back(i);
            return ans;
    }
        
        
//         soltion #2
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>freqAns(nums.size()+1);
            
//              [4,3,2,7,8,2,3,1]
//             indices [1, 2, 3, 4, 5, 6, 7, 8]
//             freq    [1, 2, 2, 1, 1, 1, 1, 1]
            for(auto k : nums)
                    freqAns[k]++;
            int j= 0;
            for(int i = 1;i < nums.size()+1;i++)
                    if(freqAns[i] > 1)
//                             modify freq array to store answer
                            freqAns[j++] = i;
            for(int i = j;i <= nums.size();i++)
                    freqAns.pop_back();
            
            return freqAns;
    }
        
//         solution #3 
        vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); ++i){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[index] *= -1;
            }
        }
        return ans;
        
    }
};
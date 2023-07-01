class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,deque<int>>m;
        map<int,int>m1;
        for(int i = 0;i < nums.size();i++){
            m[nums[i]].push_back(i);
            m1[nums[i]]++;
        }
        vector<int>res(2);
        for(int i = 0;i < nums.size();i++){

            if(target - nums[i] == nums[i]) {
                if (m1[nums[i]] > 1) {
                    res[0] = m[nums[i]].front();
                    m[nums[i]].pop_front();
                    res[1] = m[nums[i]].front();
                    break;
                }
                continue;
            }
            int val = target - nums[i];
            if(m1[val] > 0){
                res[0] = m[nums[i]].front();
                res[1] = m[val].front();
                break;
            }
        }
        return res;
        
    }
};
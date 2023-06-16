class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int>tar;
        long long left = 0, right = nums.size()-1;
        while (left <= right)
        {
            sort(nums.begin(), nums.end());
            int mid = (left + right) / 2;
            if(nums[mid] == target)tar.push_back(mid);
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
       return tar;
    }
};
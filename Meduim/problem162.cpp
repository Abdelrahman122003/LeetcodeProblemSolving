class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 
    cout.tie(nullptr);
        if(nums.size() == 1 || nums[0] > nums[1])return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])return (nums.size()-1);
        int l = 1, r = nums.size()-2;
        int mx = -1;
        while(l <= r){
          int mid = (l+r)/2;
          if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            mx = mid;
            break;
          }
          else if(nums[mid] < nums[mid+1])
          {
              l = mid+1;
          }
          else {
              r = mid-1;
            }
          }
        return mx;
        }
};
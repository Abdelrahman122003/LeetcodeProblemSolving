class Solution {
public:
// solution 1
//  Floyd’s Cycle Finding Algorithm
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
            // cout << slow << " " << fast << endl;
        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
//   solution 2

//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//             int ans = 0;
//             for(int i = 1;i < nums.size();i++)
//                     if(nums[i] == nums[i-1]){ans =nums[i];break;}
            
//             return ans;
//     }
};

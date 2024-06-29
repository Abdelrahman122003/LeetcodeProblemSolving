// First Solution -> sliding window + two heaps(min, max)

// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int l = 0, r = 0, ans = 0;
            
//             priority_queue<pair<int, int>>mx;
//             priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>mn;
//             for(; r < nums.size();r++){
//                     mn.push({nums[r], r});
//                     mx.push({nums[r], r});
//                       // Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit
//                     while(limit < mx.top().first - mn.top().first){
//                               // Move the left pointer to the right until the condition is  satisfied. This ensures we remove the element causing the violation
//                             l = min(mx.top().second, mn.top().second)+1;
                            
//                             while(l > mn.top().second)
//                                         mn.pop();
//                             while(l > mx.top().second)
//                                         mx.pop();
//                     }
//                  // Update maxLength with the length of the current valid window
//                 ans = max(ans, r - l + 1);
//             }
//              return ans;
//     }
// };

// Second Solution -> muliset + sliding window 

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0, ans = 0;
            multiset<int>s;
            for(; r < nums.size();r++){
                     s.insert(nums[r]);
                      // Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit
                    while(limit < *s.rbegin() - *s.begin()){
                              // Move the left pointer to the right until the condition is  satisfied. This ensures we remove the element causing the violation
                           s.erase(s.find(nums[l]));
                            l++;
                    }
                 // Update maxLength with the length of the current valid window
                ans = max(ans, r - l + 1);
            }
             return ans;
    }
};

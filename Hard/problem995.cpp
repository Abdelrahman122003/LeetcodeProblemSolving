// Solution

// **1) The main idea of this problem is that you must change zero to one.
//    Once you get a zero, change it to one.
// **2) The second important statement to describe this problem is that for every zero you want to change to a one, check flips. Follow me in the next statement for more details.
// **3) Depending on the number of flips, you can take action. Remember, the goal is to change all zeros to ones. During the iteration, you will check nums[i] and flips and follow these cases:

// flips = even and nums[i] is even (flip)
// flips = even and nums[i] is odd
// flips = odd and nums[i] is even
// flips = odd and nums[i] is odd (flip)
// **4) And finally, when do we decrease flips?
//    The answer is that we will mark the value of the index where we increase the flips to convert it from zero to one with any number, like 99 for example.
// **5) With every iteration, we check if nums[k - i] == 99. That value indicates that this index was increased by one to change zero to one. In this case, decrease flips by one.


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
          int filps = 0, n = nums.size(), ans = 0;
          for(int i = 0 ; i < n;i++)
          {
                  if(i >= k && nums[i-k] == 99)
                          filps--;
                  if(nums[i] == (filps&1))
                  {
                          if(i+k > n)
                                  return -1;
                          filps++;
                          ans++;
                          nums[i] = 99;
                  }
          }
          return ans;
    }
};
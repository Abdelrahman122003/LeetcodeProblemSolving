// insertion sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
            int n = nums.size();
        for(int i = 1; i < n;i++){
                int curr = nums[i]; 
                int j = i-1;
                while(j >= 0 && curr < nums[j])
                        nums[j+1] = nums[j], j--;
                nums[j+1] = curr;
        }
    }
};

// after first iteration
// 0 2 2 1 1 0

// second iteration
// 0 2 2 1 1 0

// thrid iteration
// 0 1 2 2 1 0

// fourth iteration
// 0 1 1 2 2 0

// last iteration
// 0 0 1 1 2 2


// **Solution Description:
// **Problem Statement:
// The task requires finding the k-th smallest distance among all pairs (nums[i], nums[j]) where 0 <= i < j < nums.length.

// A brute-force approach using nested loops would be too slow, leading to a "Time Limit Exceeded" error. Therefore, we need to optimize the solution.

// The minimum possible distance is 0, and the maximum possible distance is the difference between the largest and smallest elements in the array.

// Instead of trying every possible difference in a brute-force manner, we can use binary search to efficiently determine if a given difference is the k-th smallest distance.

// You might wonder: "How can we determine if a particular middle value is the k-th smallest distance?"

// Initially, it seems like brute-forcing would be required, but that approach is too slow. So, let's think about using binary search again.

// Indeed, binary search can also be applied within the countDiffer function to verify if the current middle value is the k-th smallest distance.

// **Now, let's move on to the countDiffer function:

// Within this function, we have the mid value, which represents the current difference we are testing.

// We iterate over the entire vector nums. For each index i, we calculate the difference between nums[i] and mid.


// diff=nums[i]−mid
// After calculating this difference, we use a binary search with the lower_bound function to find the index of the closest number to this diff in the vector. This helps us determine the number of elements in the range (i, st) that are smaller than the current difference.

// By subtracting the result from the current index i, we get the count of smaller numbers.

// Once the function completes, it returns the counter, which is then used in the main binary search. Based on the comparison of this counter with k, we adjust the search range by setting right = mid - 1 or left = mid + 1.


class Solution {
public:
    // let us implement countDiffer function
    int countDiffer(int mid, vector<int>& nums){
            int counter = 0, n = nums.size();
            for(int i = 0; i < n;i++){
                    auto st = lower_bound(nums.begin(), nums.begin()+i+1, nums[i] - mid) - nums.begin();
                    counter += i - st;
            }
            return counter;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
            
            sort(nums.begin(), nums.end());
            int n = nums.size(), left = 0, right = nums.back() - nums[0], ans = -1;
            while(left <= right){
                    int mid = (left + right)/2;
                    if(countDiffer(mid, nums) >= k)
                            ans = mid, right = mid - 1;
                    else
                            left = mid + 1;
            }
            return ans;
    }
};
// Solution Description

// 1) Let's explore this problem step by step.
// 2) First, imagine that we sort the `nums` array initially (sorted once in the constructor that is automatically called when the object is instantiated).
// 3) Each time a new number is added, we need to determine its correct position in the sorted `nums` vector.
//    For example:
//    Original: [3, 5, 2, 8]
//    Sorted:   [2, 3, 5, 8]
//    New number to add: 4
//    We need to find the index where 4 would fit to maintain the sorted order of `nums`.
//    Instead of using a linear search (O(N)), we can use binary search (O(log N)) to find the index efficiently.
//    The `binarySearch` function will return index 2 for the number 4.
//    Increment this index by 1 to find the correct insertion point for 4.
// 4) After finding the index, shift all numbers from this index onward to the right to make space for the new number.
//    Example:
//    Original: [2, 3, 5, 8]
//    Shifted:  [2, 3, _, 5, 8]
// 5) In code, we'll add a placeholder (e.g., 0) at the end of the `nums` vector to make room for shifting.
//    Example:
//    Before shifting: [2, 3, 5, 8, 0]
//    After shifting:
//    Step 1: [2, 3, 5, 0, 8]
//    Step 2: [2, 3, 0, 5, 8]
// 6) Place the new value at the calculated index.
// 7) Finally, return `nums.size() - k` to get the result.

class KthLargest {
public:

    int kth, n, index;
    vector<int>_nums;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        _nums = nums;
         kth = k;
    }
    int binarySearch(int left, int right, int val){
            int index = -1;
            while(left <= right){
                    int mid = (left + right)/2;
                    if(_nums[mid] <= val)
                            index = mid, left = mid + 1;
                    else 
                            right = mid-1;
            }
            return index;
    }
    int add(int val) {
        n = _nums.size();
        index = binarySearch(0, _nums.size()-1, val);
        index++;
        _nums.push_back(0);
        for(int i = n; i > index;i--)
                _nums[i] = _nums[i-1];
        
        _nums[index] = val;
        int kth_largest = _nums[_nums.size() - kth];
        return kth_largest;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
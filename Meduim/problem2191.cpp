class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Convert the numbers in nums using the mapping vector.
        // For example:
        // Given nums = {991, 338, 38}
        // and mapping = {338, 007, 7}
        // The result should be {338, 007, 7}.
        
        unordered_map<int, pair<int, int>> data;
        // <original number, <index in nums, converted number>>
        
        int j = 0;
        for (int k : nums) {
            string newNum = to_string(k);
            for (int i = 0; i < newNum.size(); ++i)
                newNum[i] = mapping[newNum[i] - '0'] + '0';
            data[k] = {j, stoi(newNum)};
            j++;
        }
        
        // Sort nums using a custom comparator based on the data map.
        // The sorting is first by the converted number, and if there are ties,
        // by the original index to preserve the original order for equal values.
        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            return (data[n1].second < data[n2].second) ||
                   (data[n1].second == data[n2].second && data[n1].first < data[n2].first);
        });
        return nums;
    }
};


// Challenge =>
// Use a different method to convert numbers instead of using the to_string() function.

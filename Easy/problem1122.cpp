// Solution 1 ==> hash table
// time complexity : O(n)

// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//         unordered_map<int, int>m;
//             unordered_set<int>s;
//             sort(arr1.begin(), arr1.end());
//             for(auto k : arr1)
//                     m[k]++;
//             for(auto k : arr2)
//                     s.insert(k);
//             vector<int>ans;
//             for(auto &k : arr2){
//                     int occur = m[k];
//                     while(occur--)
//                            ans.push_back(k);
//             }
//             for(auto k : arr1)
//                     if(!s.count(k))
//                             ans.push_back(k);
//             return ans;
//     }
// };


// Solution 2 ---> Count Sort
// Let n be the size of arr1 and m be the size of arr2. 
// Let k be the maximum element in arr1.
// time complexity : O(n + m + k)
class Solution{
        
        public:
        vector<int> relativeSortArray(vector<int>&arr1, vector<int >&arr2){
                int max = *max_element(arr1.begin(), arr1.end());
                vector<int>count(max+1, 0);
                for(auto k : arr1)
                        count[k]++;
                vector<int>ans;
                for(auto k : arr2)
                        while(count[k] > 0)
                                ans.push_back(k), count[k]--;
                for(int i = 0; i <= max;i++)
                        while(count[i] > 0)
                                ans.push_back(i), count[i]--;
                return ans;
        }
};
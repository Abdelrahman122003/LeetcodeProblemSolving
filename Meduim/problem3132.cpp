class Solution {
public:
// brute force solution
        bool check(vector<int>temp, vector<int>nums2){
                int i = 0, j = 0, count = 0; 
                while(i < temp.size() && j < nums2.size()){
                        if(nums2[j] == temp[i])
                                count++, j++;
                       i++;
                }
                return(count == nums2.size());
        }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int>diffs;
            for(int i = 0 ; i < nums1.size();i++){
                    for(int j = 0 ; j < nums2.size(); j++){
                            diffs[nums2[j] - nums1[i]]++;
                    }
            }
            int mn = 1000000;
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
           
            for(auto k : diffs){
                     vector<int>temp;
                    int diff = k.first;
                    for(int i = 0 ;i < nums1.size();i++)    
                        temp.push_back(nums1[i] + diff);
                    sort(temp.begin(), temp.end());
                   if(check(temp, nums2))
                           mn = min(mn, diff);
            }
            return mn;
    }
};
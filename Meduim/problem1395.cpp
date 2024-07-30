class Solution {
public:
    int numTeams(vector<int>& rating) {
            unordered_map<int, int>countGreater, countSmaller;
            int n = rating.size();
// **countGreater
// These loops count, for each number, how many other numbers are greater than it specifically in the indices after its current index
// **countSmaller
// In the same loop, these loops count, for each number, how many other numbers are smaller than it specifically in the indices before its current index

            for(int j = 0; j < n; j++)
            {
                    for(int k = j+1; k < n; k++)
                    {
//                          rating[j] < rating[k] < countGreater[rating[k]]
                            if(rating[j] < rating[k])
                                    countGreater[rating[j]]++;
//                          countSmaller[rating[j]] > rating[j] > rating[k]
                            if(rating[k] < rating[j])
                                    countSmaller[rating[j]]++;
                    }
                }
            int ans = 0;
            for(int j = 0; j < n; j++)
            {
                    for(int k = j+1; k < n; k++)
                    {
                            if(rating[j] < rating[k])
                                    ans += countGreater[rating[k]];
                            if(rating[k] < rating[j])
                                    ans += countSmaller[rating[k]];
                    }
            }
            return ans;
    }
};
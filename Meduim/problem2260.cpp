class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int>m;
        int mn = 1e5;
            for(int i  = 0 ;i < cards.size();i++)
            {
//                     if found in map
                    if(m.count(cards[i]))
                            // Find size of window from prev index to current index
                            mn = min(mn, i - m[cards[i]]);
                    m[cards[i]] = i;
                }
     
        return (mn == 1e5)? -1 :mn+1;
    }
};
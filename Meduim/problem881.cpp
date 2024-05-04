class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
            
            int c = 0, n = people.size();
           int l = 0, r = n-1;
            while(l <= r){
              if(people[l] + people[r] <= limit)
                      l++, r--, c++;
                else c++, r--;
            }
            return c;
    }
};
#include <vector>
#include <algorithm>

class Solution {
public:
        
   static  bool com(const vector<int>& o, const vector<int>& t){
//       sort based on end to max number of days
           // for example
//            1 1, 1 4, 2 2, 3 4, 4 4
//            if we sort based on start
//            res =  1 1, 1 4, 2 2, 3 4, 4 4
//            based on end
//             1 1, 2 2, 3 4, 4 4, 1 4
//            so sort based on end better than based on start
        return (o[1] < t[1]);
            if (o[1]==t[1]) return o[0]<t[0]; //if end is collising then sort that according to start point
           return false;
    }

    int maxEvents(vector<vector<int>>& events) {
//             we will use com function to com based on specfic condtion
        sort(events.begin(), events.end(), com);
            
            set<int>st;
            for(int i = 1 ;i <= 100000;i++)st.insert(i);
            long long count = 0;
         for(auto k : events){
              int e = k[1];
                int s = k[0];
                 //The program finds the first day in the days set that is not less than the start day s
                 auto it = st.lower_bound(s);
                 if(it == st.end() || *it > e)continue;
                 else {
                         count++;
                         st.erase(*it);
                 }
         }
        return count;
    }
};

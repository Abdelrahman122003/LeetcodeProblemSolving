class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count  = 0;
            for(auto k : arr)
            {
                    if(k%2)
                    {       
                           count++;
                           if(count>=3)
                                   return true;
                    }
                    else 
                            count = 0;
            }
            return false;
    }
};
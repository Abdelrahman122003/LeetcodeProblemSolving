class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count  = 0;
            unordered_map<int, int>m;
            m[0] = 1;
            int prefix = 0;
            for(auto i : nums)
            {
                    prefix += i;
                    int reminder = prefix % k;
                    if(reminder < 0)
                            reminder += k;
                    
                    if(m.find(reminder) != m.end()){
                            count += m[reminder];
                            m[reminder]++;
                    }
                    else
                            m[reminder] = 1;
            }
            
            return count;
    }
};

// nums : [4,5,0,-2,-3,1]
// prefix nums : [4 ,9, 9, 7, 4, 5]
// prefix after mod k : [4, 4, 4, 2, 4 , 0]


// -1 2 9
// -1 1 10
// -1 1 0

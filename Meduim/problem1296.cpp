class Solution {
public:
        // time complexity : n
    bool isPossibleDivide(vector<int>& nums, int k) {
             if (nums.size() % k) 
                return false;
                unordered_map<int, int>m;
            for(auto ii : nums)
                    m[ii]++;
            for(auto ii: nums)
            {
                    int startN = ii;
                    // Find the start of the potential straight sequence(smallest number for this sequence)
                    while(m[startN-1])
                            startN--;
//                     process from this startN untill terminate and go to next and so on.....
                    while(startN <= ii){
                            while(m[startN]){
                                    for(int i = startN; i < startN+k;i++){
                                            if(!m[i])
                                                    return false;
                                            else 
                                                    m[i]--;
                                    }
                            }
                            startN++;
                    }
            }
            return true;
            
    }
};
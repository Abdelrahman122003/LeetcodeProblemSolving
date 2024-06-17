class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c) ;i++){
                int r = c - (i * i);
                double remind = sqrt(r);
                if(remind == floor(remind))
                        return true
            }
            return false;
    }
};
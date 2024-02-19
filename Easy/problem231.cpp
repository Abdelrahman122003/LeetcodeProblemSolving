class Solution {
public:
    bool isPowerOfTwo(int n) {
            double p = log2(n);
            return (ceil(p) - p == 0)?true : false;
    }
};
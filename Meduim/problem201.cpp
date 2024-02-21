class Solution {
public:
    int rangeBitwiseAnd(int n, int m) {
        int count = 0;
//         in this problem we will iterate for each bit in left and right and count untill n == m
            while(n!= m){
                    n>>=1, m >>=1, count++;
            }
            return n<<count;
    }
};

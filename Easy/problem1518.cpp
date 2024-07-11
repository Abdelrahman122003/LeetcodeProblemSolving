class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
            while(numBottles >= numExchange)
                ans += numExchange, numBottles -= numExchange, numBottles++;  
            return ans + numBottles;
    }
};

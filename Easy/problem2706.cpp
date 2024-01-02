class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int ans = 0;
        ans = (money - (prices[0]+prices[1]) >= 0)?money - (prices[0]+prices[1]):money;

        return ans;
    }
};
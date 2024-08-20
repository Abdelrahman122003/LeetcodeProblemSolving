// Solve this problem using dynamic programming to optimize brute force by applying memoization, preventing time limit exceeded errors
class Solution {
public:
//      dp[index][m][alice or bob]
    int dp[101][101][2];
    int n;
    int solve(int index, int m, bool player, vector<int>& piles){
//             base case 
            if(index == n)
                    return 0;
            int &ret = dp[index][m][player];
            if(~ret)
                    return ret;
            ret = player? -1: 1e9;
            int sum = 0;
            for(int x = 1; x <= m*2; x++)
            {
//                  out of range
                    if(index + x - 1>= n)
                            break;
//                  Sum for the current state specified for Alice
                    sum += piles[index + x  1];
//                    alice => (player = true)  max 
                    if(player)
                           ret = max(ret, solve(index+x, max(m, x), !player, piles) + sum); 
                    else
//                     bob   => (player = false) min
                            ret = min(ret, solve(index+x, max(m, x), !player, piles));
            }
            return ret;
    }
    int stoneGameII(vector<int>& piles) {
            n = piles.size();
// Initialize a 2D array `dp` with -1 to check if `dp[][][]` has been evaluated before.
            memset(dp, -1, sizeof dp);
            return solve(0, 1, 1, piles);
    } 
};
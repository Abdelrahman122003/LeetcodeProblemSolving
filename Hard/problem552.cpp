class Solution {
public:
        static const int MOD =  1e9+7;
// Initialized dp with the size [n + 1][2][3] because the values of totalA can be 0 or 1 (since having 2 would terminate the condition), and lateConsecutive can be 0, 1, or 2 (since 3 would terminate the condition).
        

        int dp[100001][2][3];
//     day_num, count_Absent, late(consecutive days)
    int checkRecord(int n) {
            memset(dp, -1, sizeof dp);
            return solve(n, 0, 0);
    }
        
    int solve(int n, int totalA, int lateConsecutive){

            
        if(totalA >= 2 or lateConsecutive >= 3)
                return 0;
            if(n == 0)
                    return 1;
            int & ret = dp[n][totalA][lateConsecutive];
            
            if(ret != -1)
                    return ret;
            ret = 0;
            // Present
            (ret += solve(n-1, totalA, 0))%=MOD;
            // Absent
            (ret += solve(n-1, totalA+1, 0))%=MOD;
             // Late
            (ret += solve(n-1, totalA, lateConsecutive+1))%=MOD;
            return ret;
    }
};
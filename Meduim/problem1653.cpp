// Solution 
// 1)The problem revolves around this string becoming aaaaaaa|bbbbbbbb, so we will count the number of 'b's before and 'a's after the current index
// for example:
//         0 1 2 3 4 5 6 7
//         a a b a b b a b
//      a's(after)    b's(before)   index          
//             3      0              0
//             2      0              1
//             2      0              2
//             1      1              3
//             1      1              4
//             1      2              5
//             0      3              6
//             0      3              7
// 2) Make a prefix sum for 'b's because we want to delete 'b's from the beginning of the string
// 3) Make a suffix sum for 'a's because we want to delete 'a's from the end of the string
// 4) The string should become like this: aaaaaabbbbbb
// 5) Minimize the sum of the prefix sum of 'b's and the suffix sum of 'a's to get the answer

class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();
        vector<int>bBefore(n, 0), aAfter(n, 0);
        bBefore[0] = (s[0] == 'b');
        aAfter[n-1] = (s[n-1] == 'a');
        for(int i = 1; i < n ;i++)
            bBefore[i] = (s[i] == 'b') + bBefore[i-1];
        for(int i = n-2; i >= 0 ;i--)
            aAfter[i] = (s[i] == 'a') + aAfter[i+1];
         int ans = 1e9;
         for(int i = 1; i < n-1;i++)
                 ans = min(ans, bBefore[i-1] + aAfter[i+1]);
         ans = min(ans, aAfter[0]);
         ans = min(ans, bBefore[n-1]);
         return ans;
    }
};
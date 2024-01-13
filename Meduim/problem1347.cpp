class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>a(26), b(26);
            for(auto i : s)
                    a[i -'a']++;
            for(auto i : t)
                    b[i- 'a']++;
            int count = 0;
            for(int i = 0;i < 26;i++)
                    count += (a[i] > b[i])?a[i] - b[i]: 0;
            return count;
    }
};
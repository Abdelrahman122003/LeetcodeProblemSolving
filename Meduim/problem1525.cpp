class Solution {
public:
    int numSplits(string s) {
        int count  = 0;
        vector<int>pre(s.length());
        vector<int>suff(s.length());
        unordered_set<char>m1, m2;
        int l = s.length()-1;
        // cout << str.substr(3, 4) << endl;
        for (int i = 0; i < s.size(); i++)
        {
            m1.insert(s[i]);
            m2.insert(s[l-i]);
            pre[i] = m1.size();
            suff[l-i] = m2.size();
        }
        for (int i = 1; i <=l; i++)
        {
            count += (pre[i-1] == suff[i]);
        }
        
        return count;
    }
};
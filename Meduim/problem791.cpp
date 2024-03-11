class Solution {
public:
    static map<char, int> m;
    static bool com(const char a, const char b) {
        return (m[a] < m[b]);
    }
    string customSortString(string order, string s) {
        int i = 0;
        for (auto k : order)
            m[k] = i++;
        string co = "", strO = "";
        for (auto k : s)
            if (!m.count(k))
                co += k;
            else
                strO += k;
        sort(strO.begin(), strO.end(), com);
        return strO + co;
    }
};

map<char, int> Solution::m;

class Solution {
public:
    string reorganizeString(string s) {
          unordered_map<char, int>m;
        for(auto k : s)
                m[k]++;
        priority_queue<pair<int, char>>q;
        for(auto [k, v] : m)
                q.push({v, k});
            int i = 0;
        while(!q.empty()){
                pair<int, char> o = q.top();
                q.pop();
                if( 2 * o.first - 1 > s.size()) return "";
                while(o.first--)
                {
                        if(i >= s.size())i = 1;
                        s[i] = o.second;
                        i+=2;
                }
                
        }
        return s;
    }
};
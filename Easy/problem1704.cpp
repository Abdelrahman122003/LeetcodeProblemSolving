class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char>ss{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int v = 0;
            int midI = s.size()/2;
            for(int i = 0 ;i < midI;i++)
                    v+=(ss.count(s[i])), v-=(ss.count(s[i+midI]));
            
            return(!v);
    }
};
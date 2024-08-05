class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string, int>m;
            int i = 1;
            for(auto l : arr)
                    m[l]++;
            for(auto e : arr){
                    if(m[e] == 1)
                    {
                           k--;
                           if(!k)
                                return e;
                    }
            }
            return "";
    }
};


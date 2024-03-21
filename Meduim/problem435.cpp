class Solution {
public:
static bool cmp(vector<int>& a , vector<int>& b){
        if(a[1] == b[1]){
            return a[0]<b[0];
        }
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(), cmp);
        int counter = 0;
        vector<int>pre = in[0]; 
            for(int i = 1;i < in.size();i++){
                    if(in[i][0] >= pre[1])
                            pre = in[i];
                    else
                            counter++;
            }
            return counter;
    }
};
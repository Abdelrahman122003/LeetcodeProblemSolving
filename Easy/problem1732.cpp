class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         vector<int>res(gain.size());
        res[0] = gain[0];
        for(int i = 1;i<gain.size();i++){
            res[i] = res[i-1] + gain[i];
        }
        sort(res.begin(), res.end());
        if(res.back() < 0){
            return 0;
        }else{
            return res.back();
        }
    }
};
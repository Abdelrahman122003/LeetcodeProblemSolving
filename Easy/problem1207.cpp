class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>m, occure;
        for(auto k : arr){
          m[k]++;
        }
        for(auto k : m){
          occure[k.second]++;
        }
        int count = 0;
        for(auto k : occure){
          if(k.second != 1)count++;
        }
        if(!count){
          return true;
        }
        return false;
    }

};
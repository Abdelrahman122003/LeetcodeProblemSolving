class Solution {
public:
  int deToBin(int n){
    int count = 0; 
      while (n)
      {
          if(n&1)count++;
          n>>=1;
      }
      return count;
  }
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        for(int i = 1; i <= n;i++){
          v[i] = deToBin(i);
        }
        return v;
    }

};
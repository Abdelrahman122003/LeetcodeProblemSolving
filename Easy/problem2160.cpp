class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
      string s1 = "";s1 +=  str[0];s1+= str[3];
      string s2 = "";s2 += str[1];s2 += str[2];
      int r1 = stoi(s1);
      int r2 = stoi(s2); 
     int res = r1 + r2;
     return res;
    }
};
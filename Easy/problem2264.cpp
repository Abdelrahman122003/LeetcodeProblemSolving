class Solution {
public:
    string largestGoodInteger(string num) {
      string mx;
      for(int i = 0;i < num.size()-2;i++){
        string newStr = num.substr(i, 3);
        if(newStr[0] == newStr[1] && newStr[1] == newStr[2] && newStr > mx){
          mx = newStr;
        }
      }
      return mx;
    }
};
class Solution {
public:
    string removeKdigits(string str, int k) {
        int n = str.size();
        string newStr = "";
            if(n == k)return "0";
            for(int i = 0;i < n;i++){
              while(k > 0 && !newStr.empty() && newStr.back() > str[i])
                      newStr.pop_back(), k--;
                newStr.push_back(str[i]);                    
                }
//        that include many of numbers are equal during comparing
//             so we will delete from last of newStr 
//             for example : 2223
//             in this case newStr = 222 
         while(k-- > 0)newStr.pop_back();
         int j = 0;
//             to remove prefix zeros
         while(newStr[j] == '0')j++;
         newStr = newStr.substr(j);
         return newStr=="" ? "0":newStr;
    }

};
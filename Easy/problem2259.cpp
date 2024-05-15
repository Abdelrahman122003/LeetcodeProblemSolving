class Solution {
public:
    string removeDigit(string number, char digit) {
         string res = "";
            int n = number.size();
            for(int i = 0 ; i < number.size();i++){
                    if(number[i] == digit)
                    {
                            if (res == "")
                                    res = number.substr(0, i) + number.substr(i+1, n);
                             else
                                     res = max(res, number.substr(0, i) + number.substr(i+1, n));
                            
                    } 
            }                  
      return res;
    }
        
};
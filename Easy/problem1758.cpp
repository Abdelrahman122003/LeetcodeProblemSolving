class Solution {
public:
    int minOperations(string s) {
        //010
        int count_1 = 0, count_0 = 0;
            for(int i = 0 ;i < s.size();i++){
                    if(i&1){
                            if(s[i] == '1')
                                    count_0++;
                            else
                                    count_1++;
                            
                       }
                    else{
                            if(s[i] == '1')
                                    count_1++;
                            else
                                    count_0++;
                            
                    }
            }
        return min(count_1, count_0);
    }
};
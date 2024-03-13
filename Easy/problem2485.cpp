class Solution {
public:
        int summation(int n){
                 return (n * (n+1))/2;
        }
    int pivotInteger(int n) {
            if(n == 1)return 1;
           int sumAll = summation(n);
            for(int i = ceil(n/2) ;i < n;i++){
                    if((sumAll - summation(i))+i == summation(i))return i;
            }
            return -1;
    }
};
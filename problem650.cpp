class Solution {
public:
    int n;
    int minSteps(int n) {
            if(n == 1)
                    return 0;
            this->n = n;
            return 1 + solve(1, 1);
    }
    int solve(int currLenA, int pasteLen){
//             base case
            if(n == currLenA)
                    return 0;
//             base case 
//             if exceeded n `A`s
//             Return the maximum value because this problem minimizes the answer
            if(currLenA > n)
                    return 1000;
            // copy all + paste
            int opt1 =  2 + solve(currLenA * 2, currLenA);
            // paste
            int opt2 =  1 + solve(currLenA + pasteLen, pasteLen);
            return min(opt1, opt2);
    }
};
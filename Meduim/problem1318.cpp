class Solution {
public:
  int minFlips(int a, int b, int c){
      int filps = 0;
    while(a || b || c){
        bool bitA, bitB, bitC;
        bitA = (a&1);
        bitB = (b&1);
        bitC = (c&1);
        if((!bitA && bitB && !bitC) || (bitA && !bitB && !bitC))filps++;
        if(!bitA && !bitB && bitC)filps++;
        if(bitB && bitA && !bitC)filps+=2;
        a>>=1;
        b>>=1;
        c>>=1;
    }
    return filps;
  }
};
class Solution {
public:
// [1,0,0,0,0,1]
// [1,0,1,0,0,1]
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      if((flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) || !n)return true;
      if((flowerbed.size() == 1 && flowerbed[0] == 1 && n > 0) || n >= flowerbed.size())return false;
      if(flowerbed[0] == 0 && flowerbed[1] == 0){n--;flowerbed[0] = 1;}
      if(n){
        for(int i = 1;i < flowerbed.size()-1;i++){
        if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
        {
          flowerbed[i] = 1;
          n--;
          }
        }
        if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0)n--;
      }else{
        return true;
      }

      if(n <= 0)return true;
      return false;
    }
};
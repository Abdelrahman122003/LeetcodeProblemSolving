class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        stack<int>s;
        int n = asteroids.size();
        int i = 0;
        for(int i = 0;i < n;i++){
          if(s.empty())s.push(asteroids[i]);
          else{
               if((asteroids[i] > 0 && s.top() > 0) || (asteroids[i] < 0 && s.top() < 0) || s.top() < 0 && asteroids[i] > 0){
            s.push(asteroids[i]);
          }
          else{
            if(abs(asteroids[i]) < abs(s.top())){
              // s.pop();
            }else if(abs(asteroids[i]) == abs(s.top())){
              s.pop();
            }else{
              s.pop();i--;
            }
          }
          }
        }
        vector<int>v;
        while(!s.empty()){
          v.push_back(s.top());
          s.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
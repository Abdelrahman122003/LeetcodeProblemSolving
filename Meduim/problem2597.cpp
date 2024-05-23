class Solution {
public:
        int counter;
        vector<int>nus;
        int n, _k;
        unordered_map<int, int>m;
    int beautifulSubsets(vector<int>& nums, int k) {
            _k = k;
            n = nums.size();
            if(n == 1)
                    return 1;
            counter = 0;
            nus = nums;
            solve(0);
            return counter - 1;
    }
        void solve(int i){
                if(i == n){
                        counter++;
                        return;
                }
                int number = nus[i];
                if(m.find(number - _k) == m.end() &&
            m.find(number + _k) == m.end()){
                        m[number]++;
                        solve(i+1);
                         if(m[number] == 1)
                                 m.erase(number);
                        else 
                                m[number]--;
                 }
                  solve(i+1);
        }
};
class Solution {
public:
        bool decision(int mid, vector<int>p,int m){
                int lastP = p.front();
//                 Since we take the first basket, we decrement m by 1
                int remindBalls = m - 1;
                // Iterate over the positions to try placing the remaining balls
                for(int i = 1; i < p.size() && remindBalls > 0;i++)
                        if(p[i] - lastP >= mid)
                                remindBalls--, lastP = p[i];
//                If all balls can be placed, then this mid value is a valid answer
                return (remindBalls == 0);
        }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
            long long l = 1, r = position.back() - position.front(), ans = -1;
            while(l <= r){
                    long long mid = (l+r)/2;
                    int counter = m-1;
//                   If this mid value is a valid answer, maximize ans and move the left pointer.
                    if(decision(mid, position, m))
                            ans = max(ans, mid), l = mid + 1; 
                    else
                            r = mid-1;
            }
            return ans;
    }
};
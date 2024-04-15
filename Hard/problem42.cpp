class Solution {
public:
    int trap(vector<int>& height) 
    {
// First, we need to calculate the maximum height for each height[index] from the left and right
 // height = [0,1,0,2,1,0,1,3,2,1,2,1] 
//   indices  0 1 2 3 4 5 6 7 8 9 10 11  
            // example :
//             index number 2 -> heighth[2] = 0;
//             max for this index from left is equal to 1
//             max for this index from right is equal to 2
//             to calc trap_water  = min(heighth[1], heighth[2]) - heighth[2])     
            // min(2,1) - 0 = 1
            int n = height.size();
            vector<int>l(n, 0), r(n, 0);
            l[0] = height[0];
            r[n-1] = height[n-1];
            // maximum height for each height[index] from the left
            for(int i = 1;i < n;i++)
                    l[i] = max(l[i-1], height[i]);
            
//             maximum height for each height[index] from the right
            for(int i = n-2;i >= 0;i--)
                    r[i] = max(r[i+1], height[i]);
            
            int trapWater = 0;
            for(int i = 0; i < n;i++)
                    trapWater += min(r[i], l[i]) - height[i];
            return trapWater;
    }
};
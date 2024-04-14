class Solution {
public:
//  time complexity --> O(n) using monotonic stack
    int largestRectangleArea(vector<int>& heights) {
            int n =heights.size();
        vector<int>left(n, 0), right(n, n-1);
            stack<int>s;
        //first we will get nearest smallest bar(next smallest element)
        //indices   0  1  2  3  4  5 
        //original : 2  1  5  6  2  3
        // next(vector store indices of next smallest ele)   : 0 5 3 3 5 5 
            for(int i = 0;i < n;i++){
                    while(!s.empty() && heights[i] < heights[s.top()])
                    {
                            right[s.top()] = i-1;
                            s.pop();
                    }
                    s.push(i);
            }
//          clear stack first to reuse it again
            while(!s.empty())
                    s.pop();
        //second we will get pervious smallest element
        //indices   0  1  2  3  4  5 
        //original : 2  1  5  6  2  3
        // pervious(vector store indices of pervious smallest ele)   : 0 0 2 3 2 5
            for(int i = n-1;i >= 0;i--){
                    while(!s.empty() && heights[i] < heights[s.top()])
                    {
                            left[s.top()] = i+1;
                            s.pop();
                    }
                    s.push(i);
            }
//            0    1   2   3   4  5
    //original 2    1   5   6   2  3
    // right  0    5   3   3   5  5 
    // left   0    0   2   3   2  5
            int maxArea = -1;
            for(int i = 0 ;i < n;i++){
                    maxArea = max(maxArea, heights[i] * (right[i] - left[i] +1));
            }
            return maxArea;
    }
};
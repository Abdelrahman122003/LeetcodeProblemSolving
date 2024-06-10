class Solution {
public:
    int heightChecker(vector<int>& heights) {
            vector<int>sortH;
            sortH = heights;
            sort(sortH.begin(), sortH.end());
            int count = 0;
            for(int i = 0;i < heights.size();i++)
                    count += (sortH[i] != heights[i]);
            return count;
    }
};
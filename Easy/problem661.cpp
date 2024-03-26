class Solution {
public:
        vector<int>dx{0, 1, 0, 0, -1, -1, -1, 1, 1};
         vector<int>dy{0, 0, -1, 1, 0, -1, 1, -1, 1};

        
        bool check(int nx, int ny, vector<vector<int>>& img, int n,int m){
            return nx >= 0 && nx < n && ny >= 0 && ny < m;
        }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
            
            // Create a new image of the same dimension as the input image.
            int n = img.size(), m = img[0].size();
        vector<vector<int>> smoothImg(n, vector<int>(m));
            for(int i = 0;i < n;i++){
                    for(int j = 0 ;j < m;j++){
                            int ava = 0,c =0; 
                            for(int k = 0; k < 9;k++){
                                     int nx = i+ dx[k], ny = j + dy[k];
                                        if(check(nx, ny, img, n, m))c++, ava+=img[nx][ny];
                            }
                            if(c)smoothImg[i][j] = (ava/c);
                            else smoothImg[i][j] = img[i][j];
                    }
            }
            return smoothImg;
    }
};
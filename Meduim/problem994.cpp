class Solution {
public:
         vector<int>dirX{1, 0, 0, -1};
        vector<int>dirY{0, -1, 1, 0};
        bool check(int nx, int ny, int n, int  m, vector<vector<int>>& maze){
                return nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1;
        }
        int bfs( vector<pair<int, int>>rotten, vector<vector<int>>& grid, vector<vector<bool>>& visited,int n,int m){
                queue<pair<int, int>>q;
            int level = 0;
                for(auto p : rotten)
                        q.push(p);
            while(!q.empty()){
                    int size = q.size();
                    while(size--){
                            pair<int, int> top = q.front();
                            q.pop();
                            for(int i = 0;i < 4;i++){
                                    
                                    int nx = top.first + dirX[i], ny = top.second + dirY[i];
                                    if(check(nx, ny, n, m, grid) && !visited[nx][ny])
                                            q.push({nx, ny}), visited[nx][ny] = true;
                            }
                    }
                    if(!q.empty())level++;
            }
            return level; 
        }
    int orangesRotting(vector<vector<int>>& grid) {
             int n = grid.size(), m = grid[0].size();
            vector<vector<bool>> visited(n , vector<bool>(m, 0));  
            int counter = 0;
            vector<pair<int, int>>rotten;
            for(int i = 0 ; i < n;i++){
                    for(int j = 0; j < m;j++){
                            if(grid[i][j] == 2 && !visited[i][j])
                                    //  first --->  get all rotten orange 
                                    rotten.push_back({i, j});
                    }
            }
// perform a depth-first search simultaneously on them until the queue is empty, ensuring that there are no other fresh oranges adjacent to those that have become rotten
             counter = bfs(rotten, grid, visited, n, m);
            
            for(int i = 0 ; i < n;i++)
                    for(int j = 0; j < m;j++)
// In this scenario, if during the depth-first search, it is not possible to reach any other fresh oranges, then print -1.
                            if(grid[i][j] == 1 && !visited[i][j])return -1;
            
            return counter;
            
    }
};
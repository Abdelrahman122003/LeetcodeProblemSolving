class Solution {
public:
        
        vector<int>dirX{1, 0, 0, -1};
        vector<int>dirY{0, -1, 1, 0};
        bool check(int nx, int ny, int n, int  m, vector<vector<char>>& maze){
                return nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.';
        }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>>q;
            int level = 1;
            int n = maze.size(), m = maze[0].size();
            vector<vector<bool>> visited(n , vector<bool>(m, 0));  
                visited[entrance[0]][entrance[1]] = 1;              
            q.push({entrance[0], entrance[1]});
            while(!q.empty()){
                    int size = q.size();
                    while(size--){
                            pair<int, int> top = q.front();
                            q.pop();
                            for(int i = 0;i < 4;i++){
                                    int nx = top.first + dirX[i], ny = top.second + dirY[i];
                                    if(check(nx, ny, n, m, maze) && !visited[nx][ny])
                                       {     q.push({nx, ny});
                                        visited[nx][ny] = true;
                                            if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1){
                                                    return level;
                                            }
                                       }
                            }
                    }
                    level++;
            }
            return -1;
    }
};
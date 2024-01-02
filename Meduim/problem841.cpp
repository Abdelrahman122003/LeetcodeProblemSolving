class Solution {
public:
    void dfs(int node, vector<bool>&vis, vector<vector<int>>& rooms){
            vis[node] = true;
            for(auto room : rooms[node]){
                    if(!vis[room])
                            dfs(room, vis, rooms);
            }
            
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(), false);
         dfs(0, vis, rooms);
         bool ch = true;
         for(auto v : vis){
                 if(!v){
                         ch = false;
                         break;
                 }
         }
         return ch;
    }
};
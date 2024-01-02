class Solution {
public:
    bool isPathCrossing(string path) {
        map<char, pair<int ,int>>m;
        m['N'] = {0, 1};
        m['S'] = {0, -1};
        m['E'] = {1, 0};
        m['W'] = {-1, 0};
        
        int x = 0, y = 0;
        bool ans = false;
        unordered_set<string> visited;
        visited.insert("0,0");  
        for(int i = 0;i < path.size();i++){
            x+=m[path[i]].first;
            y+=m[path[i]].second;
            string h = to_string(x)+"," + to_string(y);
            if(visited.find(h) != visited.end()){
                    ans = true;
            }
            visited.insert(h);
        }
        return ans;
    }
};
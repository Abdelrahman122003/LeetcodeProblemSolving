class Solution {
public:
    // Direction vectors for moving up, down, left, and right
    vector<int> x{0, 0, -1, 1};
    vector<int> y{1, -1, 0, 0};
    int n, m; // Dimensions of the grid
    vector<vector<int>> g, g2; // g is grid1, g2 is grid2
    vector<vector<bool>> vis; // Visited matrix to keep track of visited cells in grid2
    int counter; // Counter for the number of sub-islands
    bool f; // Flag to indicate if the current island in grid2 is a sub-island of grid1

    // Function to check if a cell (i, j) is within bounds, not visited, and part of an island in grid2
    bool check(int i, int j) {
        return i < n && j < m && i >= 0 && j >= 0 && g2[i][j] && !vis[i][j];
    }

    // Depth-First Search (DFS) to explore an island in grid2
    void dfs(int i, int j) {
        vis[i][j] = true; // Mark the current cell as visited

        // If the corresponding cell in grid1 is water, set the flag to false
        if (!g[i][j]) 
            f = false;

        // Explore the four possible directions
        for (int k = 0; k < 4; k++) {
                // The decision to check the other grid (grid1) inside the next if condition is incorrect. By checking after the recursive call, it implies that the current cell is 1 in grid2, but you need to validate against grid1. Therefore, the best approach is to check grid1 before making the recursive call.
            // Check if the next cell is valid and part of the island
            if (check(i + x[k], j + y[k]))
                dfs(i + x[k], j + y[k]); // Recursively visit the next cell
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        g = grid1; 
        g2 = grid2;
        vis = vector<vector<bool>>(n, vector<bool>(m, false)); // Initialize the visited matrix
        counter = 0; // Initialize the sub-island counter

        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell in grid2 is land and has not been visited
                if (!vis[i][j] && g2[i][j]) {
                    f = true; // Assume it's a sub-island
                    dfs(i, j); // Perform DFS to explore the island
                    counter += f; // Increment counter if the flag remains true (indicating a sub-island)
                }
            }
        }

        return counter;
    }
};

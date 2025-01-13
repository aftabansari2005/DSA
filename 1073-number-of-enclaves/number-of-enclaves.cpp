class Solution {
public:
    void find(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int &ans) {
        queue<pair<int, int>> q;
        vis[i][j] = 1;
        ans++;
        q.push({i, j});
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            pair<int, int> current = q.front();
            int r = current.first;
            int c = current.second;
            q.pop();
            for (int k = 0; k < 4; k++) { // Changed from n to 4
                int drow = r + delrow[k];
                int dcol = c + delcol[k];
                if (drow >= 0 && drow < grid.size() && dcol >= 0 && dcol < grid[0].size() && 
                    !vis[drow][dcol] && grid[drow][dcol] == 1) {
                    q.push({drow, dcol});
                    vis[drow][dcol] = 1;
                    ans++;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ones = 0;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && !vis[i][j] && grid[i][j] == 1) {
                    find(grid, vis, i, j, ans);
                }
                if (grid[i][j] == 1) ones++;
            }
        }
        return ones - ans;
    }
};

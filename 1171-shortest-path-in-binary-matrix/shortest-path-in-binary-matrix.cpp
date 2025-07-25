class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int  n = grid.size();
        int m = grid[0].size();
  if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        dist[0][0]=1;
        q.push({1,{0,0}});
        int delr[]= {-1,-1,-1,0,0,1,1,1};
        int delc[]= {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto node= q.front();
            int dis=node.first;
            int row=node.second.first;
            int col = node.second.second;
            q.pop();

            if (row == n - 1 && col == m - 1)
                return dis;
            for(int i=0 ;i<8;i++){
                int drow=row+delr[i];
                int dcol=col+delc[i];
                if(drow>=0 && dcol>=0 && drow<n && dcol<m && grid[drow][dcol]==0 && dis+1<dist[drow][dcol]){
                  dist[drow][dcol]=dis+1;
                  q.push({dis+1,{drow,dcol}});
                }
            }
        }
        return -1;
    }
};
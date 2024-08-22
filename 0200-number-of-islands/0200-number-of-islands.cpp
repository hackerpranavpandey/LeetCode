class Solution {
private:
    void bfs(vector<vector<char>>& grid,int row,int col, vector<vector<int>>& vis){
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first,j=it.second;
            grid[i][j]='0';
            if(i+1<n && !vis[i+1][j] && grid[i+1][j]=='1')
                 q.push({i+1,j}),vis[i+1][j]=1;
            if(j+1<m && !vis[i][j+1] && grid[i][j+1]=='1')
                q.push({i,j+1}),vis[i][j+1]=1;
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]=='1')
                q.push({i-1,j}),vis[i-1][j]=1;
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]=='1')
                q.push({i,j-1}),vis[i][j-1]=1;
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size(),ans=0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
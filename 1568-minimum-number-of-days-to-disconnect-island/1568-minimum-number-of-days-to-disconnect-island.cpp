class Solution {
private:
    // helper function the return number of island in a grid
    int num_island(vector<vector<int>> grid){
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    ans+=1;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int i,int j){
        int n_r=grid.size();
        int n_c=grid[0].size();
        if(i<0 || j<0 || i>=n_r || j>=n_c || grid[i][j]==0)
            return;
        grid[i][j]=0;
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
public:
    int minDays(vector<vector<int>>& grid) {
        // first check numberof island present
        // if it is not equal to 1 then no need
        // now analyse the problem it will take at most 2 days to make any grid disconnected
        // now for each grid[i][j]==1 make it 0
        // then check number of island now if not equal to 1
        // so in such condition we need just one day
        // for all rest conditions need 2 days
        int number_of_islands=num_island(grid);
        if(number_of_islands!=1)
            return 0;
        int ans=2;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(num_island(grid)!=1)
                        ans=1;
                    grid[i][j]=1;
                }
            }
        }
        return ans;
    }
};
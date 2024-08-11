class Solution {
private:
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
        int number_of_islands=num_island(grid);
        if(number_of_islands!=1)
            return 0;
        vector<int> day_req;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(num_island(grid)==1)
                        day_req.push_back(2);
                    else
                        day_req.push_back(1);
                    grid[i][j]=1;
                }
            }
        }
        int min_day=2;
        for(auto& it:day_req){
            min_day=min(min_day,it);
        }
        return min_day;
    }
};
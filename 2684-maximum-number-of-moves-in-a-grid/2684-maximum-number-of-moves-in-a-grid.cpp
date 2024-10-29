class Solution {
private:
    int moveNow(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()-1)
            return 0;
        if(dp[row][col]!=-1)
            return dp[row][col];
        int moveUp=0;
        int moveDown=0;
        int moveRight=0;
        if(row-1>=0 && grid[row-1][col+1]>grid[row][col])
            moveUp=1+moveNow(grid,row-1,col+1,dp);
        if(row+1<grid.size() && grid[row+1][col+1]>grid[row][col])
           moveDown=1+moveNow(grid,row+1,col+1,dp);
        if(grid[row][col+1]>grid[row][col])
           moveRight=1+moveNow(grid,row,col+1,dp);
        dp[row][col]=max({moveUp,moveDown,moveRight});
        return dp[row][col];
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        // observe that it always has to move to the next column
        // so for each row start at first column to max ans
        // just try using the dp 2-d array for this
        // for each grid[row][col] only 3 ways are possible
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,moveNow(grid,i,0,dp));
        }
        return ans;
    }
};
class Solution {
private:
   void dfs(vector<vector<int>>& grid_matrix,int i,int j){
       int n=grid_matrix.size();
       if(i<0 || j<0 || i>=n || j>=n || grid_matrix[i][j]!=0)
           return;
       grid_matrix[i][j]=1;
       dfs(grid_matrix,i-1,j);
       dfs(grid_matrix,i+1,j);
       dfs(grid_matrix,i,j+1);
       dfs(grid_matrix,i,j-1);
   }
public:
    int regionsBySlashes(vector<string>& grid) {
        // har ke liye 3*3 matrix banao
        // phir uske badd dfs laga do simple
        int n=grid.size();
        vector<vector<int>> grid_matrix(3*n,vector<int>(3*n,0));
        // ab slash ke hisab se jaha jaha hai waha 1 karo
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    grid_matrix[i*3][j*3+2]=1;
                    grid_matrix[i*3+1][j*3+1]=1;
                    grid_matrix[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    grid_matrix[i*3+2][j*3+2]=1;
                    grid_matrix[i*3+1][j*3+1]=1;
                    grid_matrix[i*3][j*3]=1;
                }
            }
        }
        int region=0;
        for(int i=0;i<grid_matrix.size();i++){
            for(int j=0;j<grid_matrix[0].size();j++){
                if(grid_matrix[i][j]==0){
                    dfs(grid_matrix,i,j);
                    region++;
                }
            }
        }
        return region;
    }
};
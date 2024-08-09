class Solution {
private:
    bool magic_square(vector<vector<int>>& grid,int row_start,int col_start){
         // find sum along any row_start
         // then check for each row 
         // similar for column then make a vector diff
         // index from 0 to 9 each value as 0
         // first check if grid[i][j] is between 0 and 9 
         // then also check if diff[grid[i][j]]>0 this will help in knowing
         // that all the values are from 1 to 9
         // at end check for all the diagonals
        int sum=0;
        for(int i=col_start;i<col_start+3;i++){
            sum+=grid[row_start][i];
        }
        // check for each row
        for(int i=row_start;i<row_start+3;i++){
            int next_sum=0;
            for(int j=col_start;j<col_start+3;j++){
                next_sum+=grid[i][j];
            }
            if(next_sum!=sum)
                return false;
        }
        vector<int> diff(10,0);
        // check for each column
         for(int i=col_start;i<col_start+3;i++){
            int next_sum=0;
            for(int j=row_start;j<row_start+3;j++){
                next_sum+=grid[j][i];
                if(grid[j][i]<1 || grid[j][i]>9 || diff[grid[j][i]]!=0)
                    return false;
                diff[grid[j][i]]++;
            }
            if(next_sum!=sum)
                return false;
        }
        int d_1=grid[row_start][col_start]+grid[row_start+1][col_start+1]+grid[row_start+2][col_start+2];
        int d_2=grid[row_start][col_start+2]+grid[row_start+1][col_start+1]+grid[row_start+2][col_start];
        if(d_1!=sum || d_2!=sum)
            return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row<3 || col<3)
            return 0;
        int ans=0;
        // for each 0 to row-2 and 0 to col-2
        // check if the matrix 3*3 is magic square or not 
        // if it is then increment answer by 1
        for(int i=0;i<row-2;i++){
            for(int j=0;j<col-2;j++){ 
                if(magic_square(grid,i,j))
                    ans++;
            }
        }
        return ans;
    }
};
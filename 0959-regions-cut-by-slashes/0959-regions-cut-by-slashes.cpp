class Solution {
private:
    const vector<vector<int>> DIRECTIONS = {{0,1},{0,-1},{1,0},{-1,0}};
    // Flood fill algorithm to mark all cells in a region
    void floodfill(vector<vector<int>>& expandedGrid,int row,int col){
        queue<pair<int,int>> q;
        expandedGrid[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            auto [currentRow,currentCol] = q.front();
            q.pop();
            // check all four directions
            for(const auto& direction: DIRECTIONS){
                int newRow = direction[0] + currentRow;
                int newCol= direction[1] + currentCol;
                if(isValidCell(expandedGrid,newRow,newCol)){
                    expandedGrid[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
    
    bool isValidCell(const vector<vector<int>>& expandedGrid,int row,int col){
        int n=expandedGrid.size();
        return row >= 0 && col>=0 && row<n && col<n && expandedGrid[row][col]==0;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
       // so the logic is to treat the slashes and grid boundaries as water
       // and the remaining cells as land
       // it becomes same as finding number of islands problem
        // so this question is combination of different other leetcode problems
        // one is number of island and another one if flooodFill algorithm
        // so understand dfs, bfs and floodFill algorithm to solve this question
        int gridSize=grid.size();
        vector<vector<int>> expandedGrid(gridSize*3,vector<int>(gridSize*3,0));
        for(int i=0;i<gridSize;i++){
            for(int j=0;j<gridSize;j++){
                int baseRow=i*3;
                int baseCol=j*3;
                if(grid[i][j]=='\\'){
                    expandedGrid[baseRow][baseCol]=1;
                    expandedGrid[baseRow+1][baseCol+1]=1;
                    expandedGrid[baseRow+2][baseCol+2]=1;
                }
                else if(grid[i][j]=='/'){
                    expandedGrid[baseRow][baseCol+2]=1;
                    expandedGrid[baseRow+1][baseCol+1]=1;
                    expandedGrid[baseRow+2][baseCol]=1;
                }
            }
        }
        int region_count=0;
        // count regions using flood fill algorithms
        for(int i=0;i<gridSize*3;i++){
            for(int j=0;j<gridSize*3;j++){
                if(expandedGrid[i][j]==0){
                    floodfill(expandedGrid,i,j);
                    region_count++;
                }
            }
        }
        return region_count;
    }
};
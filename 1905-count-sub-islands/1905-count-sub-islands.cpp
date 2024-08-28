class Solution {
private:
    bool part_of_island(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i ,int j){
        int m=grid1.size(),n=grid1[0].size();
        queue<pair<int,int>> t;
        // index ko store karlo
        // phir check karo ki grid1 me har index pe 1 hai ya nhi
        // vector<pair<int,int>> index;
        // can be done just using a single variable instead of this vector
        bool is_present=true;
        t.push({i,j});
        while(!t.empty()){
            auto it=t.front();
            t.pop();
            int r=it.first,c=it.second;
            if(grid1[r][c]!=1)
                is_present=false;
            // index.push_back(it);
            if(r+1<m && grid2[r+1][c]==1){
                grid2[r+1][c]=0;
                t.push({r+1,c});
            }
            if(c+1<n && grid2[r][c+1]==1){
                grid2[r][c+1]=0;
                t.push({r,c+1});
            }
            if(r-1>=0 && grid2[r-1][c]==1){
                grid2[r-1][c]=0;
                t.push({r-1,c});
            }
            if(c-1>=0 && grid2[r][c-1]==1){
                grid2[r][c-1]=0;
                t.push({r,c-1});
            }
        }
        // for(auto it:index){
        //     if(grid1[it.first][it.second]!=1)
        //         return false;
        // }
        return is_present;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // so the idea is same as from the number of island problem 
        // just one difference here is that
        // here if the island is there in grid2 then all the corresponding cells in grid1 
        // should also be 0
        int ans=0;
        int m=grid1.size(),n=grid1[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    if(part_of_island(grid1,grid2,i,j)==true)
                        ans++;
                }
            }
        }
        return ans;
    }
};
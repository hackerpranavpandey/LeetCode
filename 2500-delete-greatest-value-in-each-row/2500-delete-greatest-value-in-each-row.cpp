class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // vector<int> max_vec(grid[0]);
        // sort(max_vec.begin(),max_vec.end(),greater<int>());  // sort it in order
        // for(int i=0;i<m;i++){
        //     sort(grid[i].begin(),grid[i].end(),greater<int>());
        //     for(int j=0;j<n;j++){
        //         max_vec[j]=max(max_vec[j],grid[i][j]); 
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans+=max_vec[i];
        // }
        // return ans;
        int ans=0;
        for(int i=0;i<m;i++){
            sort(grid[i].begin(),grid[i].end(),greater<int>());
        }
        for(int i=0;i<n;i++){
            int max_removed=grid[0][i];
            for(int j=0;j<m;j++){
                max_removed=max(max_removed,grid[j][i]);
            }
            ans+=max_removed;
        }
        return ans;
    }
};
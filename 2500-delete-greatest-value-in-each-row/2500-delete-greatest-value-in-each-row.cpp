class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> max_vec(grid[0]); // this vector will store the max value after each of removal
        sort(max_vec.begin(),max_vec.end(),greater<int>());  // sort it in order
        for(int i=1;i<m;i++){
            sort(grid[i].begin(),grid[i].end(),greater<int>());
            for(int j=0;j<n;j++){
                max_vec[j]=max(max_vec[j],grid[i][j]); 
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max_vec[i];
        }
        return ans;
    }
};
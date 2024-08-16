class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size(),m=arrays[0].size()-1;
        int min_value=arrays[0][0],max_value=arrays[0][m];
        int ans=0;
        for(int i=1;i<n;i++){
            m=arrays[i].size()-1;
            ans=max(ans,max(abs(arrays[i][m]-min_value),abs(max_value-arrays[i][0])));
            min_value=min(min_value,arrays[i][0]);
            max_value=max(max_value,arrays[i][m]);
        }
        return ans;
    }
};
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            vector<int> t(n,0);
            for(int j=0;j<n;j++){
                t[j]=1-matrix[i][j];
            }
            int tanisha=0;
            for(int j=0;j<m;j++){
                if(matrix[j]==t || matrix[j]==matrix[i])
                     tanisha++;
            }
            ans=max(ans,tanisha);
        }
        return ans;
    }
};
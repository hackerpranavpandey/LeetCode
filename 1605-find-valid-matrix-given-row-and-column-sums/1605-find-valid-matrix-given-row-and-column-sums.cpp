class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows=rowSum.size();
        int columns=colSum.size();
        vector<vector<int>> ans(rows,vector<int>(columns,0));
        // now traverse through each rowSum[i] and keep on plcaing until it become zero
        for(int i=0;i<rows;i++){
            while(rowSum[i]!=0){
                for(int j=0;j<columns;j++){
                    ans[i][j]=min(rowSum[i],colSum[j]);
                    rowSum[i]-=ans[i][j];
                    colSum[j]-=ans[i][j];
                    if(rowSum[i]==0)
                        break;
                }
            }
        }
        return ans;
    }
};
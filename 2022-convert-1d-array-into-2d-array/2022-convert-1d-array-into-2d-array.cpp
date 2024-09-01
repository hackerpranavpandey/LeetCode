class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size())
            return {};
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            vector<int> row;
            for(int j=i*n;j<(i+1)*n;j++){
                row.push_back(original[j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
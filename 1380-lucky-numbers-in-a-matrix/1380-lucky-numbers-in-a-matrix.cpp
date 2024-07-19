class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_set<int> row_min;
        vector<int> column_max(m,-1);
        for(vector<int> v:matrix){
            int min_value=INT_MAX;
            for(int i=0;i<m;i++){
                column_max[i]=max(column_max[i],v[i]);
                min_value=min(min_value,v[i]);
            }
            row_min.insert(min_value);
        }
        vector<int> ans;
        for(int num:column_max){
            if(row_min.find(num)!=row_min.end())
                ans.push_back(num);
        }
        return ans;
    }
};
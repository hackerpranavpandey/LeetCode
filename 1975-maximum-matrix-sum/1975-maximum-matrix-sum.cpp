class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // count negative if even then there is way to make all of them positive
        // otherwise except minimum abs(matrix[i][j]) all will be part of ans
        long long ans=0;
        int min_t=INT_MAX;
        int count=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=abs(matrix[i][j]);
                min_t=min(min_t,abs(matrix[i][j]));
                count+=(matrix[i][j]<0);
            }
        }
        if(count%2==0)
            return ans;
        return (ans-2*min_t);
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // so its like the concept of binary search for two times
        // so visualising binary search in 2-D space
        int row=matrix.size();
        int col=matrix[0].size();
        int left=0;
        int right=(row*col)-1;
        while(left<=right){
            int mid=(left+right)/2;
            int i=mid/col;
            int j=mid%col;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};
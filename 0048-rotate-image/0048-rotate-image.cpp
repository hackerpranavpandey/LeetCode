class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // one simple program could be to just use same size matrix and then perform the transpose
        // this problem is very used in the qr code analysis
        // so use simple concept for now first find the transpose
        // then reverse each of the row then
        int row=matrix.size();
        int col=matrix[0].size();
        // find transpose 
        // for that don't just simply swap for each cell
        // first do it for first left half of the matrix
        for(int i=0;i<row;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
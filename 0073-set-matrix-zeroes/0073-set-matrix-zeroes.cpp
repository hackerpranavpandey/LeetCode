class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> row_zeros(row,0);
        vector<int> col_zeros(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    row_zeros[i]++;
                    col_zeros[j]++;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(row_zeros[i]>0 || col_zeros[j]>0)
                    matrix[i][j]=0;
            }
        }
        // above algorithm is fine but lets do it in constant space
        // for that we will use first element of each row and each column as flag to determine
        //  for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(matrix[i][j]==0){
        //             matrix[i][0]=0;
        //             if(j!=0)
        //                 matrix[0][j]=0;
        //         }
        //     }
        // }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(matrix[i][j]!=0){
        //             if(matrix[i][0]==0 || matrix[0][j]==0)
        //                 matrix[i][j]=0;
        //         }
        //     }
        // }
    }
};
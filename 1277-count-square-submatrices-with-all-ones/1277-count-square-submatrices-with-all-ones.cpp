class Solution {
private:
    // given the value of t1 and matrix it return s umber of square matrix of size t1*t1
    int solve(int t1,vector<vector<int>>& matrix){
        int m=matrix.size(),n=matrix[0].size();
        int rowStart=0,rowEnd=t1-1;
        int totalSquare=0;
        while(rowEnd<m){
            int colStart=0,colEnd=t1-1;
            while(colEnd<n){
                int count=0;
                for(int t=rowStart;t<=rowEnd;t++){
                    for(int z=colStart;z<=colEnd;z++){
                       if(matrix[t][z])
                           count++;
                       else{
                           count=-1;
                           break;
                       }
                    }
                    if(count==-1)
                        break;
                }
                if(count==pow(t1,2))
                    totalSquare++;
                colStart++,colEnd++;
            }
            rowStart++,rowEnd++;
        }
        return totalSquare;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        // one way to count all possible square from size 1 to min(m,n)
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j])
                    ans++;
            }
        }
        int maxSquare=min(m,n);
        for(int i=2;i<=maxSquare;i++){
            ans+=solve(i,matrix);
        }
        return ans;
        
    }
};
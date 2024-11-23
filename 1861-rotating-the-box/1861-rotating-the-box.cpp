class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>> t(n,vector<char>(m,'.'));
        for(int i=m-1;i>=0;i--){
             while(true){
                 int find=0;
                 for(int j=0;j<n;j++){
                     if(box[i][j]=='#' && j+1<n && box[i][j+1]=='.'){
                         find++;
                         swap(box[i][j],box[i][j+1]);
                     }
                 }
                 if(find==0)
                     break;
             }
             for(int j=0;j<n;j++){
                 t[j][m-1-i]=box[i][j];
             }
        }
        return t;
    }
};
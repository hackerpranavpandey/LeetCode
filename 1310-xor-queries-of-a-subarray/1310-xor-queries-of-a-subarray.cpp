class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // int n=arr.size();
        // vector<vector<int>> x_or(n,vector<int>(n,0));
        // for(int i=0;i<n;i++){
        //     x_or[i][i]=arr[i];
        //     for(int j=i+1;j<n;j++){
        //         x_or[i][j]=x_or[i][j-1]^arr[j];
        //     }
        // }
        // vector<int> ans;
        // for(int i=0;i<queries.size();i++){
        //     ans.push_back(x_or[queries[i][0]][queries[i][1]]);
        // }
        // return ans;
        // above code exceeds the memory limit
        vector<int> ans;
        for(vector<int> q:queries){
            int x_or=0;
            for(int i=q[0];i<=q[1];i++){
                x_or^=arr[i];
            }
            ans.push_back(x_or);
        }
        return ans;
    }
};
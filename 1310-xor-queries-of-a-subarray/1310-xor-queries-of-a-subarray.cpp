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
        // vector<int> ans;
        // for(vector<int> q:queries){
        //     int x_or=0;
        //     for(int i=q[0];i<=q[1];i++){
        //         x_or^=arr[i];
        //     }
        //     ans.push_back(x_or);
        // }
        // return ans;
        // above is a simple iterative approach which works fine tbut this canbe done in O(n)
        int n=arr.size();
        vector<int> xor_array(n+1,0);
        for(int i=0;i<n;i++){
            xor_array[i+1]=xor_array[i]^arr[i];
        }
        vector<int> ans;
        for(vector<int> q:queries){
            ans.push_back(xor_array[q[1]+1]^xor_array[q[0]]);
        }
        return ans;
    }
};
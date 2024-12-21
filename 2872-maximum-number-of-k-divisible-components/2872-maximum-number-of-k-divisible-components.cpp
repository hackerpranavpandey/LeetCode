class Solution {
private:
    int solve(vector<vector<int>>& adj,vector<int>& values,int k,int curr,int &ans,int parent=-1){
        int sum=values[curr];
        for(int negh:adj[curr]){
            if(negh!=parent)
                sum+=solve(adj,values,k,negh,ans,curr);
        }
        sum%=k;
        if(sum==0)
            ans++;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // so easy simple sum track at each node where sum is sum of all the values at root node
        // wherever sum%k==0 add 1 to answer
        vector<vector<int>> adj(n);
        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans=0;
        int t=solve(adj,values,k,0,ans);
        return ans;
    }
};
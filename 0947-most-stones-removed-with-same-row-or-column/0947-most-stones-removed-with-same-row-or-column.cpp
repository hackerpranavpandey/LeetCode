class Solution {
private:
    void dfs(vector<vector<int>>& adj,vector<bool>& vis,int stone){
        vis[stone]=true;
        for(int neighbour:adj[stone]){
            if(vis[neighbour]==false)
                dfs(adj,vis,neighbour);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
      int n=stones.size();
      // adj list for connected components
      vector<vector<int>> adj(n);
      for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
              // either row or column matches
              if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                  adj[i].push_back(j),adj[j].push_back(i);
          }
      }
      int num=0;
      vector<bool> vis(n,false);
      for(int i=0;i<n;i++){
          // if 1 is fint hen mark visited to all connected components
          if(!vis[i]){
              dfs(adj,vis,i);
              num++;
          }
      }
      return n-num;
    }
};
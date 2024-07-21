class Solution {
    // using the concept of topoligical sorting and dfs
private:
    vector<int> topoSort(vector<vector<int>>& edges,int n){
        vector<vector<int>> adjacent(n+1);
        vector<int> order;
        vector<int> visited(n+1,0);
        bool has_cycle=false;
        for(auto& it:edges){
            adjacent[it[0]].push_back(it[1]);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs(i,adjacent,visited,order,has_cycle);
                if(has_cycle==true)
                    return {};
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
    void dfs(int i,vector<vector<int>>& adjacent,vector<int>& visited,vector<int>& order,bool& has_cycle){
        visited[i]=1;
        for(int neighbors:adjacent[i]){
            if(visited[neighbors]==0){
                dfs(neighbors,adjacent,visited,order,has_cycle);
                if(has_cycle==true)
                    return;
            }
            else if(visited[neighbors]==1){
                has_cycle=true;
                return;
            }
        }
        visited[i]=2;
        order.push_back(i);
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> orderRows=topoSort(rowConditions,k);
        vector<int> orderColumns=topoSort(colConditions,k);
        if(orderRows.empty() || orderColumns.empty())
            return {};
        vector<vector<int>> matrix(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(orderRows[i]==orderColumns[j])
                    matrix[i][j]=orderRows[i];
            }
        }
        return matrix;
    }
};
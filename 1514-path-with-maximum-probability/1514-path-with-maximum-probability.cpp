class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        int i=0;
        for(vector<int> edge:edges){
            int u=edge[0],v=edge[1];
            double prob=succProb[i];
            adj[u].push_back({v,prob}),adj[v].push_back({u,prob}),i++;
        }
        vector<double> dist(n,0);
        priority_queue<pair<double,int>> p_q;  // prob,node
        p_q.push({1,start_node});
        dist[start_node]=1.0;
        while(!p_q.empty()){
            auto it=p_q.top();
            p_q.pop();
            for(auto t:adj[it.second]){
                if(dist[t.first]<(it.first*t.second)){
                    dist[t.first]=it.first*t.second;
                    p_q.push({it.first*t.second,t.first});
                }
            }
        }
        return dist[end_node];
    }
};
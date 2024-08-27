class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // so it is simple pplication of dijkstras algorithm
        // instead of weight use probability and max heap instead of min heap
        // lets make adjacent list at first
        vector<pair<int,double>> adj[n];  // each adj[i] will have asjacent nodes and probability
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob}),adj[v].push_back({u,prob});
        }
        // no instead of weights in case of dijkstra use probability for traversal here
        priority_queue<pair<double,int>> p_q;
        p_q.push({1,start_node});  // probability for reaching start_node form start_node is 1
        vector<double> dist(n,0);
        dist[start_node]=1.0;
        while(!p_q.empty()){
            auto it=p_q.top();
            p_q.pop();
            // now visit each adjacent node
            for(auto t:adj[it.second]){
                double prob=t.second;
                int node=t.first;
                // agar it.second se node reach karne ka probability jyada ha tab
                // ke case me usko update karke priority queue me push karna hoga
                if((prob*it.first) > dist[node]){
                    dist[node]=prob*it.first;
                    p_q.push({prob*it.first,node});
                }
            }
        }
        return dist[end_node];
        }
};
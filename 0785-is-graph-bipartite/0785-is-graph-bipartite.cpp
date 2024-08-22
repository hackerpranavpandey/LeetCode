class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        // assuing two different set to store node 
        // queue ds 
        // vis set to avoid revisiting
        // it may not be fully connected so traverse for each node
        unordered_set<int> a,b;
        queue<int> t;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            // if already visited move to next node
            if(vis.find(i)!=vis.end())
                continue;
            // push in set a
            a.emplace(i);
            t.push(i);
            // try bfs with condition that if current node is in a then adjacent should be in b
            // and vice versa also
            while(!t.empty()){
                auto it=t.front();
                t.pop();
                if(vis.find(it)!=vis.end())
                    continue;
                vis.insert(it);
                if(a.find(it)!=a.end()){
                    for(int node:graph[it]){
                        if(a.find(node)!=a.end())
                            return false;
                        t.push(node);
                        b.insert(node);
                    }
                }
                else{
                    for(int node:graph[it]){
                        if(b.find(node)!=b.end())
                            return false;
                        a.insert(node);
                        t.push(node);
                }
            }
        }
    }
        return true;
    }
};
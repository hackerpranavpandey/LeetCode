class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_set<int> a,b;
        queue<int> t;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            if(vis.find(i)!=vis.end())
                continue;
            a.emplace(i);
            t.push(i);
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
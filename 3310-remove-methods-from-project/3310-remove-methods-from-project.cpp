class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> mpp;
        for(vector<int> v:invocations){
            mpp[v[0]].push_back(v[1]);
        }
        vector<int> temp;
        for(int i=0; i<n; i++){
            temp.push_back(i);
        }
        queue<int> q;
        q.push(k);
        unordered_set<int> vis;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            vis.insert(t);
            for(auto it:mpp[t]){
                if(vis.find(it)==vis.end())
                    vis.insert(it),q.push(it);
            }
        }
        vector<int> t;
        for(int i=0;i<n;i++){
            t.push_back(i);
        }
        // remove none of suspecious
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end()){
                 for(auto it:mpp[i]){
                    if(vis.find(it)!=vis.end())
                        return t;
                }   
            }
        }
        vector<int> ans;
        // remove all suspecious values
        for(int i=0;i<n;i++){
            if(vis.find(i)==vis.end())
                ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> t(n);
        for(int i=0;i<n-1;i++){
            t[i].push_back(i+1);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0],v=queries[i][1];
            t[u].push_back(v);
            int steps=0;
            queue<int> t2;
            unordered_set<int> vis;
            t2.push(0);
            vis.emplace(0);
            while(!t2.empty()){
                int t3=t2.size();
                bool find=0;
                for(int i=0;i<t3;i++){
                    int curr=t2.front();
                    t2.pop();
                    if(curr==n-1){
                        find=1;
                        break;
                    }
                    for(int road:t[curr]){
                        if(!vis.count(road))
                            vis.insert(road),t2.push(road);
                    }
                }
                if(find)
                    break;
                steps++;
            }
            ans.push_back(steps);
        }
        return ans;
    }
};
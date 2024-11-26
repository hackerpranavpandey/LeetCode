class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // there is only one node wit indegree 0 else -1
        unordered_map<int,int> indegree;
        for(vector<int> edge:edges){
            int u=edge[0],v=edge[1];
            indegree[v]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(!indegree.count(i)){
                if(ans!=-1)
                    return -1;
                ans=i;
            }
        }
        return ans;
    }
};
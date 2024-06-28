class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> freq_count(n,0);
        int m=roads.size();
        for(int i=0;i<m;i++){
            freq_count[roads[i][0]]+=1;
            freq_count[roads[i][1]]+=1;
        }
        sort(freq_count.begin(), freq_count.end(), greater<int>());
        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum=freq_count[i]*(n-i);
            ans+=sum;
        }
        return ans;
    }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // below logic is correct but it is not passing few test case at end
        // so used the dp appraoch to further solve the problem
        // unordered_set<string> dict;
        // for(string s:dictionary){
        //     dict.emplace(s);
        // }
        // int ans=0;
        // int n=s.size();
        // vector<int> t(n,0);
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         string curr=s.substr(i,j-i+1);
        //         if(dict.find(curr)!=dict.end()){
        //             for(int k=i;k<=j;k++){
        //                 t[k]=1;
        //             }
        //         }
        //     }
        // }
        // for(int k:t){
        //     if(k==0)
        //         ans++;
        // }
        // return ans;
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        int n=s.size();
        // index i tak kitne extra character hai
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=i-1;j>=0;j--){
                string curr=s.substr(j,i-j);
                if(dict.count(curr))
                    dp[i]=min(dp[i],dp[j]);
            }
        }
        return dp[n];
    }
};
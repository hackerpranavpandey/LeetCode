class Solution {
private:
    // dp array in terms of current string lenght and copied one lenght
    vector<vector<int>> dp;
    int solve(string prev_copy,string s,int n){
    // the issue comes when return 0 for both s.size()>=n for s.size()==n return 0
    if(s.size()==n)
        return 0;
    // but if it exceeds n then return some large value sine need exactly n A
    if(s.size()>n)
        return 1000;
    if(dp[s.size()][prev_copy.size()]!=0)
        return dp[s.size()][prev_copy.size()];
    int p_1=2+solve(s,s+s,n); // copy then paste
    int p_2=1+solve(prev_copy,s+prev_copy,n);  // paste previous copy only
    dp[s.size()][prev_copy.size()]=min(p_1,p_2);
    return dp[s.size()][prev_copy.size()];
}
public:
    int minSteps(int n) {
        if(n==1)
            return 0;
        // so the logic for recursion is simple either copy the prev copied string
        // or make a new copy of current string
        // return minimum steps required out of both of them
        dp=vector<vector<int>>(n+1,vector<int>(n/2+1,0));
        int ans=1+solve("A","A",n);
        return ans;
    }
};
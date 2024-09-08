class Solution {
public:
    // long long solve(vector<int>& nums,int index,int end,vector<vector<long long>>& dp){
    //     if(index>=nums.size() || end>=nums.size())
    //         return 0;
    //     if(dp[index][end]!=-1)
    //         return dp[index][end];
    //     long long ans=0;
    //     ans=max((1LL*nums[index]*(end-index))+solve(nums,end,end+1,dp),solve(nums,index,end+1,dp));
    //     dp[index][end]=ans;
    //     return ans;
    // }
    long long findMaximumScore(vector<int>& nums){
        // vector<vector<long long>> dp(nums.size(),vector<long long>(nums.size(),-1));
        // long long ans=solve(nums,0,1,dp);
        // return ans;
        // above is the code using dynamic pogramming approach which results in memory limit exceed
        // now using greedy we can get the correct way
        // so idea for greesy is that to traverse normally and check if nums[j]>nums[i]
        // but keep the end case when j reaches n so two pointer + greedy
        int i=0,j=0,n=nums.size();
        long long ans=0;
        while(j<n){
            if(nums[j]>nums[i])
                ans+=(1LL*nums[i]*(j-i)),i=j;
            if(j==n-1)
                ans+=(1LL*nums[i]*(j-i));
            j++;
        }
        return ans;
    }
};
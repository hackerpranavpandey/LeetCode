class Solution {
public:
    int rob(vector<int>& nums) {
         // so the dp formula could be
        //  dp[i]=max(dp[i-1],dp[i-2]+nums[i])
        // base cases
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
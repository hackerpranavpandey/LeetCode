class Solution {
public:
    int rob(vector<int>& nums) {
        // so here it is similar to the house robber problem 1
        // the difference lies in that we cannot rob both the first and the last house
        // so first remove the last house then use general dp formula
        // after that remove the first house then use the dp formula
        // return the max of possible for both of them
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        // removing the last house
        vector<int> dp_1(n-1,-1);
        dp_1[0]=nums[0];
        dp_1[1]=max(dp_1[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp_1[i]=max(dp_1[i-1],dp_1[i-2]+nums[i]);
        }
        // now removing the first house
        vector<int> dp_2(n-1,-1);
        dp_2[0]=nums[1];
        dp_2[1]=max(dp_2[0],nums[2]);
        for(int i=2;i<n-1;i++){
            dp_2[i]=max(dp_2[i-1],dp_2[i-2]+nums[i+1]);
        }
        return max(dp_1[n-2],dp_2[n-2]);
    }
};
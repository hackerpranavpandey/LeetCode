class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max_sum=nums[0];
        for(auto it:nums){
            sum+=it;
            max_sum=max(max_sum,sum);
            if(sum<0)
                sum=0;
        }
        return max_sum;
    }
};
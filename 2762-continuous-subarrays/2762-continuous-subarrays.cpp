class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0, windowSize;
        int left=0,right=0;
        int max_value=nums[0], min_value=nums[0];
        for(right=0;right<nums.size();right++){
            max_value=max(max_value,nums[right]);
            min_value=min(min_value,nums[right]);
            if(max_value-min_value > 2){
                windowSize = right-left;
                ans += (windowSize*(windowSize+1)/2);
                left=right;
                max_value = nums[right];
                min_value = nums[right];
                while(left>0 && abs(nums[right]-nums[left-1])<=2){
                    left--;
                    min_value=min(min_value,nums[left]);
                    max_value=max(max_value,nums[left]);
                }
                if(left < right){
                    windowSize= right-left;
                    ans -= (windowSize*(windowSize+1)/2);
                }
            }
        }
        windowSize = right-left;
        ans += (windowSize*(windowSize+1)/2);
        return ans;
    }
};
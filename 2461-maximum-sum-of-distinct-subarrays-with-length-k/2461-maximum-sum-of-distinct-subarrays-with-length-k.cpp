class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long sum=0;
        unordered_map<int,int> tanisha;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            tanisha[nums[i]]++;
        }
        if(tanisha.size()==k)
            ans=sum;
        for(int i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            tanisha[nums[i]]++;
            tanisha[nums[i-k]]--;
            if(!tanisha[nums[i-k]])
                tanisha.erase(nums[i-k]);
            if(tanisha.size()==k)
                ans=max(ans,sum);
        }
        return ans;
    }
};
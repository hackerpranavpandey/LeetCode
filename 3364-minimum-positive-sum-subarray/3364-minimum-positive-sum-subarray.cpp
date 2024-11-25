class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            int j=0;;
            int sum=0;
            while(j<nums.size()){
                sum+=nums[j];
                if(j>=i)
                    sum-=nums[j-i];
                if(sum>0 && j>=i-1)
                    ans=min(ans,sum);
                j++;
            }
        }
        return (ans==INT_MAX ? -1 : ans);
    }
};
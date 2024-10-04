class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int ans=0,sum=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
                rem+=k;
            ans+=mpp[rem];
            mpp[rem]++;
        }
        return ans;
    }
};
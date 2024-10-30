class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // once peak element is choosen then it is easy
        // so for each element find the LIS and also LDS after that
        int n=nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    lis[i]=max(lis[i],lis[j]+1);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j])
                    lds[i]=max(lds[i],lds[j]+1);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(lis[i]>1 && lds[i]>1)
                ans=min(ans,n+1-lis[i]-lds[i]);
        }
        return ans;
    }
};
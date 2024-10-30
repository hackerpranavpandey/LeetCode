class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        vector<int> t1(n,0);
        vector<int> t2(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])
                t1[i]=t1[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                t2[i]=t2[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(t1[i]>0 && t2[i]>0)
                ans=max(ans,t1[i]+t2[i]+1);
        }
        return ans;
    }
};
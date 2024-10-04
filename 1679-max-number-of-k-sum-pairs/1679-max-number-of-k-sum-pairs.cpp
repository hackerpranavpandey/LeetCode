class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // it is same as number of pairs with sum equals k
        int n=nums.size();
        // int start=0,end=n-1,ans=0;
        // sort(nums.begin(),nums.end());
        // while(start<end){
        //     if(nums[start]+nums[end]==k){
        //         ans++;
        //         start++,end--;
        //     }
        //     else if(nums[start]+nums[end]>k){
        //         end--;
        //     }
        //     else{
        //         start++;
        //     }
        // }
        // return ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int rem=k-nums[i];
            if(nums[i]==rem){
                if(mpp[rem]>=2)
                    mpp[rem]-=2,ans++;
            }
            else if(mpp.find(rem)!=mpp.end() && mpp[rem]>0 && mpp[nums[i]]>0){
                mpp[nums[i]]--,mpp[rem]--,ans++;
            }
        }
        return ans;
    }
};
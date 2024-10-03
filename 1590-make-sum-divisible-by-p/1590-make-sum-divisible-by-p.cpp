class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum=0;
        for(int num:nums){
            total_sum+=num;
        }
        if(total_sum%p==0)
            return 0;
        else if(total_sum<p)
            return -1;
        // int n=nums.size(),ans=INT_MAX;
        // vector<long long> prefix_sum;
        // prefix_sum.push_back(nums[0]);
        // for(int i=1;i<n;i++){
        //     prefix_sum.push_back(prefix_sum[i-1]+nums[i]);
        //     long long rest=total_sum-prefix_sum[i];
        //     // int div=rest,rem=rest%p;
        //     // int req=(p*(div+1)-rem);
        //     // if(rem==0 && i!=(n-1))
        //     //     return i+1;
        //     // else if(prefix_sum.find(req)!=prefix_sum.end())
        //     //     return (i-prefix_sum[req]+1);
        //     for(int j=i-1;j>=0;j--){
        //         if((rest+prefix_sum[j])%p==0){
        //             ans=min(ans,i-j);
        //             break;
        //         }
        //     }
        // }
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;
        // the concept of sum does not work so lets use the concept of mod
        unordered_map<int,int> mpp;
        int n=nums.size();
        int current_sum=0,ans=n;
        total_sum%=p;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            current_sum=(current_sum+nums[i])%p;
            int req= (current_sum-total_sum+p)%p;
            if(mpp.find(req)!=mpp.end()){
                ans=min(ans,i-mpp[req]);
            }
            mpp[current_sum]=i;
        }
        if(ans==n)
            return -1;
        return ans;
    }
};
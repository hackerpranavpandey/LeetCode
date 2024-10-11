class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     if((i%2==0 && nums[i]%2==0) || (i%2==1 && nums[i]%2==1))
        //         continue;
        //     else if(i%2==0){
        //         // swap with first odd
        //         for(int j=i+1;j<nums.size();j++){
        //             if(nums[j]%2==0){
        //                 swap(nums[i],nums[j]);
        //                 break;
        //             }
        //         }
        //     }
        //     else{
        //         // swap with first even
        //         for(int j=i+1;j<nums.size();j++){
        //             if(nums[j]%2==1){
        //                 swap(nums[i],nums[j]);
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return nums;
        int n=nums.size();
        vector<int> ans(n);
        int even=0,odd=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                ans[even]=nums[i],even+=2;
            else
                ans[odd]=nums[i],odd+=2;
        }
        return ans;
    }
};
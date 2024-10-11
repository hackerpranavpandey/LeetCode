class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // total 3 ways to solve this question - O(n^2) , T=O(n),S=O(n), O(n)
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
        // O(n) time and O(n) space
        // int n=nums.size();
        // vector<int> ans(n);
        // int even=0,odd=1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==0)
        //         ans[even]=nums[i],even+=2;
        //     else
        //         ans[odd]=nums[i],odd+=2;
        // }
        // return ans;
        int evenIndex=0,oddIndex=1,n=nums.size();
        while(evenIndex<n && oddIndex<n){
            while(evenIndex<n && nums[evenIndex]%2==0){
                evenIndex+=2;
            }
            while(oddIndex<n && nums[oddIndex]%2==1){
                oddIndex+=2;
            }
            if(evenIndex<n && oddIndex<n){
                swap(nums[evenIndex],nums[oddIndex]);
            }
        }
        return nums;
    }
};
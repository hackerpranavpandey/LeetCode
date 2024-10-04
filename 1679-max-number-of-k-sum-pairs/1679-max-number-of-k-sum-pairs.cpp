class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // it is same as number of pairs with sum equals k
        int n=nums.size();
        int start=0,end=n-1,ans=0;
        sort(nums.begin(),nums.end());
        while(start<end){
            if(nums[start]+nums[end]==k){
                ans++;
                start++,end--;
            }
            else if(nums[start]+nums[end]>k){
                end--;
            }
            else{
                start++;
            }
        }
        return ans;
    }
};
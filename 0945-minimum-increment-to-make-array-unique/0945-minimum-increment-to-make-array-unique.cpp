class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int diff= abs(nums[i]-nums[i-1]);
                nums[i]=nums[i]+diff+1;
                ans=ans+diff+1;
            }
        }
        return ans;
    }
};
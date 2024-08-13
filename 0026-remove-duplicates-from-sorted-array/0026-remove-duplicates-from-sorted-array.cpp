class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int ans=1;
       int n=nums.size();
       int index=1;
       for(int i=1;i<n;i++){
           if(nums[i-1]!=nums[i]){
               ans++;
               nums[index]=nums[i];
               index++;
           }
       }
       return ans;
    }
};
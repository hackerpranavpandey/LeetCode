class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i] <= 2*k){
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};
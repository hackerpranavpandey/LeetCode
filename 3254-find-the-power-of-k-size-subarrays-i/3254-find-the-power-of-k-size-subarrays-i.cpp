class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)
            return nums;
        int t=nums.size();
        vector<int> ans(t-k+1,-1);
        for(int i=0;i<=t-k;i++){
            for(int j=i+1;j<i+k;j++){
                if(nums[j]!=nums[j-1]+1)
                    break;
                else if(j==i+k-1)
                    ans[i]=nums[j];
            }
        }
        return ans;
    }
};
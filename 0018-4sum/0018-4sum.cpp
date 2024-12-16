class Solution {
private:
    vector<vector<int>> kSum(vector<int>& nums,long long target,int start,int k){
        vector<vector<int>> ans;
        if(start==nums.size())
            return ans;
        long long avg=target/k;
        if(nums[start]>avg || avg>nums.back())
            return ans;
        if(k==2)
            return twosum(nums,target,start);
        for(int t=start;t<nums.size();t++){
            if(t==start || nums[t]!=nums[t-1]){
                for(vector<int>& sub:kSum(nums,static_cast<long long>(target)-nums[t],t+1,k-1)){
                    ans.push_back({nums[t]});
                    ans.back().insert(end(ans.back()),begin(sub),end(sub));
                }
            }
        }
        return ans;
    }
    vector<vector<int>> twosum(vector<int>& nums,long long target,int start){
        vector<vector<int>> ans;
        int left=start, right=nums.size()-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum<target || (left>start && nums[left]==nums[left-1]))
                left++;
            else if(sum>target || (right<nums.size()-1 && nums[right]==nums[right+1]))
                right--;
            else{
                ans.push_back({nums[left],nums[right]});
                left++;
                right--;
            }
        }
        return ans;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,target,0,4);
    }
};
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // it is simple code so it exceeds the time limit
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // if(n==1 || nums[0]==nums[n-1])
        //     return 0;
        // else if(n==2)
        //     return abs(nums[0]-nums[1]);
        // int ans=0;
        // while(nums[0]!=nums[n-1]){
        //     ans++;
        //     for(int i=0;i<n-1;i++){
        //         nums[i]++;
        //     }
        //     sort(nums.begin(),nums.end());
        // }
        // return ans;
        // it is simply the sum of differences of all elements of array with minimum value
        int min_value=nums[0],n=nums.size();
        for(auto it:nums){
            min_value=min(min_value,it);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+nums[i]-min_value;
        }
        return ans;
    }
};
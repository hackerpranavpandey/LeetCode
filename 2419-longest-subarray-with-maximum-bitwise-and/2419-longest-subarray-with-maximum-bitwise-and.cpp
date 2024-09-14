class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int ans=nums[0],max_size=1,n=nums.size();
        // for(int i=0;i<n;i++){
        //     int curr_and=nums[i];
        //     if(i==n-1 && curr_and>ans)
        //         max_size=1;
        //     for(int j=i+1;j<n;j++){
        //         curr_and=curr_and & nums[j];
        //         if(curr_and>=ans)
        //             ans=curr_and,max_size=(j-i+1);
        //     }
        // }
        // return max_size;
        // above is a brute force approach
        // the bitwise and of any two value is strictly less than minimum of them
        // so the idea is to find the maximum value and its consectutive index size
        int max_value=0,n=nums.size();
        for(int i=0;i<n;i++){
            max_value=max(max_value,nums[i]);
        }
        int ans=1,prev=0;
        for(int i=0;i<n;i++){
            if(nums[i]==max_value)
                prev++;
            else
                prev=0;
            ans=max(ans,prev);
        }
        return ans;
    }
};
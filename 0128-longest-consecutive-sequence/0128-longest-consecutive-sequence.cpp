class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // idea using sorting
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int start=0;
        int end=1;
        int ans=0;
        int sub=0;
        while(end<nums.size()){
            if(nums[end-1]==nums[end])
                end++,sub++;
            else if((nums[end-1]+1)==nums[end])
                end++;
            else{
                ans=max(ans,end-start-sub);
                sub=0;
                start=end;
                end++;
            }
        }
        ans=max(ans,end-start-sub);
        return ans;
        // idea of sorting is wrong approach
        // since it asked for the sequence
        
    }
};
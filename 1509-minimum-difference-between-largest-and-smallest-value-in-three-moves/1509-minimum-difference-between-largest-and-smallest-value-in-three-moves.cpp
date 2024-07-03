class Solution {
public:
    int minDifference(vector<int>& nums) {
        // this is simple problem 
        // so there will be 4 cases
        // either change all 3 smallest,3 largest,1 smallest 2 largest and 2 1
        // so use that case
        if(nums.size()<=4)
            return 0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-4;
        int ans=INT_MAX;
        while(i<4){
            ans=min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};
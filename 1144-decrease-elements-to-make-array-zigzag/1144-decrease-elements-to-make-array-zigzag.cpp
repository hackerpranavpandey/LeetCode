class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                int t=0;
                if(i-1>=0 && nums[i-1]<=nums[i])
                    t=(nums[i]-nums[i-1]+1);
                if(i+1<nums.size() && nums[i]>=nums[i+1])
                    t=max(t,nums[i]-nums[i+1]+1);
                even+=t;
            }
            else{
                int t=0;
                if(i-1>=0 && nums[i-1]<=nums[i])
                    t=(nums[i]-nums[i-1]+1);
                if(i+1<nums.size() && nums[i]>=nums[i+1])
                    t=max(t,nums[i]-nums[i+1]+1);
                odd+=t;
            }
        }
        return min(even,odd);
    }
};
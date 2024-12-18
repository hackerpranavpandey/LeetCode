class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> ans;
        while(nums.size()!=1){
            vector<int> curr(nums.size()/2,0);
            for(int i=0;i<curr.size();i++){
                if(i%2==0)
                    curr[i]=min(nums[2*i],nums[2*i+1]);
                else
                    curr[i]=max(nums[2*i],nums[2*i+1]);
            }
            nums=curr;
        }
        return nums[0];
    }
};
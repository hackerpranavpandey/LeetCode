class Solution {
public:
    int find(vector<int>& nums,int j){
        int n = 0;
        for(int i = j; i<nums.size();i+=2){
            int l = 0;
            if(i-1>=0 && nums[i-1]<=nums[i]) l = max(l,abs(nums[i]-nums[i-1])+1);
            if(i+1<nums.size() && nums[i+1]<=nums[i]) l = max(l,abs(nums[i]-nums[i+1])+1);
            n+=l;
        }
        return n;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(find(nums,0),find(nums,1));
    }
};
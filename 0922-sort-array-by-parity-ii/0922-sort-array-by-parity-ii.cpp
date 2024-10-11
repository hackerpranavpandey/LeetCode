class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if((i%2==0 && nums[i]%2==0) || (i%2==1 && nums[i]%2==1))
                continue;
            else if(i%2==0){
                // swap with first odd
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]%2==0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
            else{
                // swap with first even
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]%2==1){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
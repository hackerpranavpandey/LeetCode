class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int low=0;       // low se mid-1 tak 0 hoga
        // int mid=0;        // mid se high tak 1 hoga 
        // int high=nums.size()-1;
        // while(mid<=high){
        //     if(nums[mid]==0){
        //         swap(nums[low],nums[mid]);
        //         low+=1;
        //         mid+=1;
        //     }
        //     else if(nums[mid]==1){
        //         mid+=1;
        //     }
        //     else{
        //         swap(nums[mid],nums[high]);
        //         high--;
        //     }
        // }
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
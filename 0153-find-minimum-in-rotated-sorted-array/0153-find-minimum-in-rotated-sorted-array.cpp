class Solution {
public:
    int findMin(vector<int>& nums) {
        // duplicates nhi hai tab index nikalne wala chalega 
        int low=0;
        int high=nums.size()-1;
        int min_value=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            // agar left part sorted hai tab uske sabse pehle se min_value ko update karo
            // aur ab right part pe search karo
            // yahi condition right part ke liye bhi likho
            if(nums[low]<=nums[mid]){
                min_value=min(min_value,nums[low]); // tab ab left part me traverse mat karo
                low=mid+1;
            }
            else{
                min_value=min(min_value,nums[mid]);
                high=mid-1;
            }
        }
        return min_value;
    }
};
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // ye question same hai but isme problem hai ki duplicate elements bhi ho sakte hai
        // jisme ek condition me kaam nhi karega
        // [3,1,2,3,3,3,3] isme arr[low]==arr[mid]==arr[high] 
        // cannot do with that code
        // so need one extra condition for arr[low]==arr[mid]==arr[high]
        // for that case just srink the array low++ and high--
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return true;
            // bas yai ek extra condition hai
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
            }
            // case for sorted left
            else if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            // for sorted right half one
            else{
                if(target>nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};
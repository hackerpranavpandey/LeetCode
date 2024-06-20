class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // linear search se aasani se kiya ja sakgta hai
        // lekin binary search bhi use kar sakte hai
        // like nums[mid] pehle check karo kahi ye single nhi hai
        // uske baad agar har element 2 bar aaya hai tab left aur right subarray ka lenght
        // batayega kis part me hai single value
        // jaise pehle test case dekho mid 3 2 bar hai aur right me nhi left part me hai tab
        // aur left part ka lenght 3 ko chor kar odd hai tab usme hi single element hai
        int low=0;
        int high=nums.size()-1;
        int single_element=nums[0];
        while(low<=high){
            int mid=(low+high)/2;
            // left half me mid ek bar aur aaya hai
            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                if((mid-1)%2==0)
                    low=mid+1;
                else
                    high=mid-1;
                    
            }
            else if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                if((mid+1)%2==0)
                    high=mid-1;
                else
                     low=mid+1;
            }
            else{
                return nums[mid];
            }
        }
        return single_element;
    }
};
class Solution {
public:
    int search(vector<int>& arr, int target) {
        // since it is sorted and search
        // lets use binary search
        // then there is a small check that for each arr[mid] check which part is sorted
        // then accodingly compare the sorted section with section and check if target is there
        // so there will be two condition that eithere left or right half will be sorted
        // so it is like check first which part is sorted
        // the  using that logic we can compare and check if it is in the left half or right half
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            // bas 3 condition lagane hai yaha pe
            if(arr[mid]==target)
                return mid;
            // agar left half sorted hai tab
            else if(arr[mid]>=arr[low]){
                // check if target is in left half since here it is sorted
                if(target>=arr[low] && target<arr[mid]){
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            // ye case tab hoga jab right half sorted hai
            else{
                // check if target is in left half since here it is sorted
                if(target>arr[mid] && target<=arr[high]){
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};
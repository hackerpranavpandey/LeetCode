class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=1,end=arr.size()-2;
        while(start<=end){
            int mid=(start+end)/2;
            if(mid>0 && mid<arr.size()-1 && arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                return mid;
            else if(arr[mid]>arr[mid-1])
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
};
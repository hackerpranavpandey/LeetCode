class Solution {
private:
    int merge(vector<int>& arr,int low,int mid,int high){
        int count=0;
        int left=low;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            // this part if left is less
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            // this is what is matter of concern since right part is smaller
            else{
                count+=(mid-left+1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return count;
    }
    int countpairs(vector<int>& nums,int low,int mid,int high){
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            if(right>high){
                count+=(mid-i+1)*(right-(mid+1));   
                break;
            }
            long long curr=static_cast<long long>(nums[right]);
            while(right<=high && nums[i]>static_cast<long long>(2*curr)){
                right++;
                if(right<=high)
                    curr=nums[right];
            }
            count+=(right-(mid+1));
        }
        return count;
    }
    int mergesort(vector<int>& arr,int low,int high){
        if(low>=high)
            return 0;
        int count=0;
        int mid=(low+high)/2;
        count+=mergesort(arr,low,mid);
        count+=mergesort(arr,mid+1,high);
        count+=countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        // brute force solutions
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         long long curr=nums[j];
        //         curr*=2;
        //         if(nums[i]>curr)
        //             count++;
        //     }
        // }
        // return count;
        // damn its time limit exceeded
        // it is quite different from count inversion problem so there is need to have other algorithms 
        // just call count pairs function before merge
        return mergesort(nums,0,nums.size()-1);
    }
};
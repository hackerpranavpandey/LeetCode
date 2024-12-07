class Solution {
private:
    int compute(vector<int>& nums,int mid){
        int t=0;
        for(int num:nums){
            t+=(num-1)/mid;
        }
        return t;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // damn it s simple binary search algorithm
        int max_value=INT_MIN;
        for(int num:nums){
            max_value=max(max_value,num);
        }
        int ans=max_value;
        int min_value=1;
        while(min_value<=max_value){
            int mid=(min_value+max_value)/2;
            int opr=compute(nums,mid);
            if(opr<=maxOperations){
                max_value=mid-1;
                ans=mid;
            }
            else
                min_value=mid+1;
        }
        return ans;
    }
};
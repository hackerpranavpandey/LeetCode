class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        // for any index find all subarray possible till that index
        // store the sum in arr
        // then sort arr and return sum of values from index left-1 to right-1
        for(int i=0;i<n;i++){
            int sum=nums[i];
            arr.push_back(nums[i]);
            for(int j=i-1;j>=0;j--){
                sum+=nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        long long ans=0;
        int mod=1000000007;
        int start=left-1;
        int end=right-1;
        while(start<=end){
            ans+=arr[start];
            start++;
            ans%=mod;
        }
        return static_cast<int>(ans);
    }
};
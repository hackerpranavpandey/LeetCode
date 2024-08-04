class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
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
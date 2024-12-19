class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // just use same as prefix sum logic
        // keeping in mind that it now with duplicates valeus too
        vector<int> sorted_arr(arr.begin(),arr.end());
        sort(sorted_arr.begin(),sorted_arr.end());
        long long sum=0;
        long long sorted_sum=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            sorted_sum+=sorted_arr[i];
            if(sum==sorted_sum)
                ans++;
        }
        return ans;
    }
};
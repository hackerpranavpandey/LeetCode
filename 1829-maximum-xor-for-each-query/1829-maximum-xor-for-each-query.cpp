class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // just see how we can compute the value of k for each subarray
        // find k for which the xor becomes 2^maximumBit -1
        int n=nums.size();
        int t=0;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            t=(t ^ nums[i]);
            int curr=t;
            int req=0;
            for(int i=0;i<maximumBit;i++){
                if(!(curr&1))
                    req+=pow(2,i);
                curr=curr>>1;
            }
            ans[n-1-i]=req;
        }
        return ans;
    }
};
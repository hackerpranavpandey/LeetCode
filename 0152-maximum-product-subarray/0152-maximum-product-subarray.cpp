class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            int product=nums[i],t;
            t=product;
            for(int j=i+1;j<n;j++){
                product*=nums[j];
                t=max(t,product);
            }
            ans=max(ans,t);
        }
        return ans;
    }
};
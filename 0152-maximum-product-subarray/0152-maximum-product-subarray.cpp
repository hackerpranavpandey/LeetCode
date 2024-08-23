class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // below algorithm is fine but it takes O(n^2) time
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
        // lets try to apply kandanes algorithms twice
    }
};
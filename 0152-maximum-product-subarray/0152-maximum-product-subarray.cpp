class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // below algorithm is fine but it takes O(n^2) time
        // int ans=INT_MIN,n=nums.size();
        // for(int i=0;i<n;i++){
        //     int product=nums[i],t;
        //     t=product;
        //     for(int j=i+1;j<n;j++){
        //         product*=nums[j];
        //         t=max(t,product);
        //     }
        //     ans=max(ans,t);
        // }
        // return ans;
        // lets use the concept of kadane algorithm
        // but twice once from forwqrd another from backward
        int max_value=INT_MIN;
        int prod=1;
        for(int num:nums){
            prod*=num;
            max_value=max(max_value,prod);
            if(!prod)
                prod=1;
        }
        prod=1;
        for(int j=nums.size()-1;j>=0;j--){
            prod*=nums[j];
            max_value=max(max_value,prod);
            if(!nums[j])
                prod=1;
        }
        return max_value;
    }
};
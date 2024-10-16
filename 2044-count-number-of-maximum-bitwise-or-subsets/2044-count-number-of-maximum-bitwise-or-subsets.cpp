class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // lets find the maximum bitwise or among all subsets
        // then find number of such subsets
        int n=nums.size();
        int totalSubset=pow(2,n)-1;
        int max_value=INT_MIN,ans=0;
        for(int i=0;i<=totalSubset;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if(i & 1<<j)
                    curr=(curr | nums[j]);
            }
            if(curr>max_value)
               ans=1,max_value=curr;
            else if(curr==max_value)
                ans++;
        }
        return ans;
    }
};
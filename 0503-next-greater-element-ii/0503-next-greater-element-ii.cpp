class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return {-1};
        stack<int> monotonic;
        monotonic.push(nums[n-1]);
        vector<int> ans(n,INT_MIN);
        for(int i=n-2;i>=0;i--){
            while(!monotonic.empty()){
                if(monotonic.top()>nums[i])
                    break;
                else
                    monotonic.pop();
            }
            if(!monotonic.empty())
                ans[i]=monotonic.top();
            monotonic.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(ans[i]==INT_MIN){
                for(int j=0;j<i;j++){
                    if(nums[j]>nums[i]){
                        ans[i]=nums[j];
                        break;   
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MIN)
                ans[i]=-1;
        }
        return ans;
    }
};
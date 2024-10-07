class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // first do dimple monotonic stack concept
        // since nums[i] can be negative so cannot assign -1 to ans
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
        // now for the case of circular order
        // if ngl is not found then in that case
        // look from index 0 to i th index
        // first greater vaue will be ngl
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
        // replace with -1
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MIN)
                ans[i]=-1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int req_sum=mean*(m+n); // compute the remaining sum
        for(int roll:rolls){
            req_sum-=roll;
        }
        // invalid case
        if(req_sum>6*n || req_sum<n)
            return {};
        int new_mean=req_sum/n;
        vector<int> ans(n,new_mean);
        // now in case it is not completely divisible
        // then for that case we need to add the remaining left value
        // remaining left=req_sum%n
        for(int i=0;i<req_sum%n;i++){
            ans[i]++;
        }
        return ans;
    }
};
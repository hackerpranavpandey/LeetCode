class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq_1;
        for(int it:nums){
            pq_1.emplace(it);
        }
        while(k>0){
            int value=pq_1.top();
            pq_1.pop();
            pq_1.emplace(value+1);
            k--;
        }
        long long ans=1;
        int MOD=1000000007;
        while(!(pq_1.size()==0)){
            ans=(ans*pq_1.top())%MOD;
            pq_1.pop();
        }
        return ans;
    }
};
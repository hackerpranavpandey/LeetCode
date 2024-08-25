class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int mod=1000000007;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p_q;
        int i=0;
        for(int num:nums){
            p_q.push({num,i}),i++;
        }
        for(int i=0;i<k;i++){
            auto it=p_q.top();
            p_q.pop();
            int index=it.second;
            int new_number=(int)((1LL*it.first*multiplier)%mod);
            p_q.push({new_number,index});
        }
        while(!p_q.empty()){
            auto it=p_q.top();
            p_q.pop();
            nums[it.second]=it.first;
        }
        return nums;
    }
};
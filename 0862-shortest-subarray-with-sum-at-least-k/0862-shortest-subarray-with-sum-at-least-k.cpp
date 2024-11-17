class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long sum=0;
        int ans=INT_MAX;
        deque<pair<long long,int>> t;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=k)
                ans=min(ans,i+1);
            pair<int,int> t2={INT_MIN,INT_MIN};
            while(t.size()>0 && sum-t.front().first>=k){
                t2=t.front();
                t.pop_front();
            }
            if(t2.first!=INT_MIN)
                ans=min(ans,i-t2.second);
            while(t.size()>0 && sum<=t.back().first){
                t.pop_back();
            }
            t.push_back({sum,i});
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
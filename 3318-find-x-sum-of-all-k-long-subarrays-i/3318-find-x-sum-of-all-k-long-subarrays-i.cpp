class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans(n-k+1,0);
        priority_queue<pair<int,int>> t;
        unordered_map<int,int> freqCount;
        for(int i=0;i<k;i++){
            freqCount[nums[i]]++;
        }
        for(int i=0 ;i<=n-k ;i++){
            t = priority_queue<pair<int,int>>();
            for(auto it:freqCount){
                t.push({it.second,it.first});
            }
            int xSum=0;
            for(int j=0;j<x && !t.empty() ;j++){
                xSum+=(t.top().first*t.top().second);
                t.pop();
            }
            freqCount[nums[i]]--;
            if(freqCount[nums[i]]==0)
                    freqCount.erase(nums[i]);
            if(i<n-k)
                freqCount[nums[i+k]]++;
            ans[i]=xSum;
        }
        return ans;
    }
};
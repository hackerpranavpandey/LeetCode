class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // push the frequency and the element in the priority queue
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        for(auto it:freq){
            pq.push(make_pair(it.second,it.first));
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
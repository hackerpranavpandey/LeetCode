class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> t;
        for(int i=0;i<nums.size();i++){
            t.push({nums[i],i});
        }
        long long score=0;
        unordered_set<int> t2;
        while(!t.empty()){
            if(t2.find(t.top().second)==t2.end()){
                score += t.top().first;
                t2.insert(t.top().second);
                t2.insert(t.top().second-1);
                t2.insert(t.top().second+1);
            }
            t.pop();
        }
        return score;
    }
};
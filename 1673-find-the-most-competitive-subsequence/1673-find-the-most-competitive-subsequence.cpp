class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> t;
        for(int i=0;i<nums.size();i++){
            while(!t.empty() && nums[i]<t.top() && nums.size()-i > k-t.size()){
                t.pop();
            }
            if(t.size() < k)
                t.push(nums[i]);
        }
        vector<int> ans;
        while(!t.empty()){
            ans.push_back(t.top());
            t.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
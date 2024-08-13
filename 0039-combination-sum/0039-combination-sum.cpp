class Solution {
private:
    void solve(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& ds,int index,int target){
        if(index==candidates.size()){
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(candidates[index]<=target){
            // first include it then exclude it
            ds.push_back(candidates[index]);
            solve(candidates,ans,ds,index,target-candidates[index]);
            ds.pop_back();
        }
        // case for not including index value
        solve(candidates,ans,ds,index+1,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates,ans,ds,0,target);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // simply using the conceptof bitwise manipulation
        int n=nums.size();
        long long t_1=pow(2,n);
        set<vector<int>> ans;
        for(int i=0;i<t_1;i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if(i & (1<<j))
                    subset.push_back(nums[j]);
            }
            sort(subset.begin(),subset.end());
            ans.emplace(subset);
        }
        vector<vector<int>> final_subset;
        for(auto it:ans){
            final_subset.push_back(it);
        }
        return final_subset;
    }
};
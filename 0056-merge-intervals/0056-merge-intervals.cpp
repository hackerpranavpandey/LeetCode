class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        int start=0;
        int max_value=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>max_value){
                vector<int> sub_merge={intervals[start][0],max_value};
                ans.push_back(sub_merge);
                start=i;
            }
            max_value=max(max_value,intervals[i][1]);
        }
        // last case
        vector<int> sub_merge={intervals[start][0],max_value};
        ans.push_back(sub_merge);
        return ans;
    }
};
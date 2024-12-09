class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // simple logic of using the array number they belongs to
        // values can be same so use index as key
        unordered_map<int,int> t;
        t[0]=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if((nums[i-1]%2)!=(nums[i]%2))
                t[i]=t[i-1];
            else
                t[i]=t[i-1]+1;
        }
        int t2=queries.size();
        vector<bool> ans(t2,false);
        for(int i=0;i<t2;i++){
            int startIndex=queries[i][0],endIndex=queries[i][1];
            if(t[startIndex]==t[endIndex])
                ans[i]=true;
        }
        return ans;
    }
};
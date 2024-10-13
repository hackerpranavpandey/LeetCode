class Solution {
private:
    static bool comp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans(n-k+1,0);
        for(int i=0;i<n-k+1;i++){
            unordered_map<int,int> freq;
            for(int j=i;j<i+k;j++){
                freq[nums[j]]++;
            }
            vector<pair<int,int>> v1;
            for(auto it:freq){
                v1.push_back({it.second,it.first});
            }
            sort(v1.begin(),v1.end(),comp);
            int xSum=0;
            for(int j=0;j<min(x,(int)v1.size());j++){
                xSum+=(v1[j].first*v1[j].second);
            }
            ans[i]=xSum;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> num_mapped;
        for(int i=0;i<nums.size();i++){
            int v=nums[i];
            int t=0;
            int tens=1;
            if(nums[i]==0){
                num_mapped.push_back({mapping[0],i});
                continue;
            }
            while(v!=0){
                int rem=v%10;
                t=(mapping[rem]*tens)+t;
                v/=10;
                tens*=10;
            }
            num_mapped.push_back({t,i});
        }
        sort(num_mapped.begin(),num_mapped.end());
        vector<int> ans;
        for(auto it:num_mapped){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};
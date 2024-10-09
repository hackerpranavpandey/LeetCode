class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto num:nums){
            count[num]++;
        }
        int ans=0;
        for(auto it:count){
            int div=it.second/3;
            ans+=div;
            if(it.second==1)
                return -1;
            else if(it.second%3==1)
                ans+=1;
            else if(it.second%3==2)
                ans+=1;
        }
        return ans;
    }
};
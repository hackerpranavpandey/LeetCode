class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        long long skill_sum=0;
        for(auto it:skill){ 
            skill_sum+=it;
        }
        if(skill_sum%(n/2)!=0)
            return -1;
        int req_sum = skill_sum/(n/2);
        sort(skill.begin(),skill.end());
        long long ans=0;
        int start=0,end=n-1;
        while(start<end){
            if(skill[start]+skill[end] != req_sum)
                return -1;
            ans+=(skill[start]*skill[end]);
            start++,end--;
        }
        return ans;
    }
};
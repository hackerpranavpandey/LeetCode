class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> scoreBit(32,0);
        for(int i=0;i<candidates.size();i++){
            int j=0;
            while(candidates[i]>0){
                if(candidates[i]&1)
                    scoreBit[j]++;
                j++;
                candidates[i]>>=1;
            }
        }
        int ans=0;
        for(auto &it:scoreBit){
            ans=max(ans,it);
        }
        return ans;
    }
};
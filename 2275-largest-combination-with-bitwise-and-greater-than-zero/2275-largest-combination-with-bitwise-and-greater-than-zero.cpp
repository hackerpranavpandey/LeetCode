class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> storeBit(32,0); // to store the bits conversion of all numbers
        for(auto& candidate:candidates){
            int i=0;
            while(candidate){
                if(1 & candidate)
                    storeBit[i]++;
                candidate=candidate>>1;
                i++;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            ans=max(ans,storeBit[i]);
        }
        return ans;
    }
};
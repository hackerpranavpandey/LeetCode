class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq_1(26,0),freq_2(26,0);
        for(char c:s){
            freq_1[c-'a']++;
        }
        for(char c:t){
            freq_2[c-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=abs(freq_1[i]-freq_2[i]);
        }
        return ans;
    }
};
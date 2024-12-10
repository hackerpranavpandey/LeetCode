class Solution {
public:
    int maximumLength(string s) {
        // it is so easy so best way is to try all the possible substring ans keep its frequency count
        unordered_map<string,int> freq_count;
        for(int i=0;i<s.size();i++){
            string t="";
            for(int j=i;j<s.size();j++){
                if(t.size()==0 || t.back()==s[j]){
                    t+=s[j];
                    freq_count[t]++;
                }
                else
                    break;
            }
        }
        int ans=0;
        for(auto &it:freq_count){
            if(it.first.size()>ans && it.second>=3)
                ans=it.first.size();
        }
        if(ans==0)
            return -1;
        return ans;
    }
};
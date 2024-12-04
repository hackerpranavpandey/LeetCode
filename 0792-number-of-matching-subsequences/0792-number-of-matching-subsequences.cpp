class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> count;
        for(string word:words){
            count[word]++;
        }
        int ans=0;
        for(auto &t:count){
            int t1=0,t2=0;
            while(t1<s.size() && t2<t.first.size()){
                if(s[t1]==t.first[t2])
                    t1++,t2++;
                else
                    t1++;
            }
            if(t2==t.first.size())
                ans+=t.second;
        }
        return ans;
    }
};
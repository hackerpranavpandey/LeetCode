class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(char c:allowed){
            s.emplace(c);
        }
        int ans=0;
        for(string t:words){
            bool t_2=true;
            for(char c:t){
                if(s.find(c)==s.end())
                    t_2=false;
            }
            if(t_2)
                ans++;
        }
        return ans;
    }
};
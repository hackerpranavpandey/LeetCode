class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int i=0,n=s1.size();
        unordered_map<string,int> t_1,t_2;
        while(i<n){
            string c="";
            while(s1[i]!=' ' && i<n){
                c+=s1[i];
                i++;
            }
            i++;
            t_1[c]++;
        }
        i=0,n=s2.size();
        while(i<n){
            string c="";
            while(s2[i]!=' ' && i<n){
                c+=s2[i];
                i++;
            }
            i++;
            t_2[c]++;
        }
        vector<string> ans;
        for(auto it:t_1){
            if(it.second==1 && t_2.find(it.first)==t_2.end())
                ans.push_back(it.first);
        }
        for(auto it:t_2){
            if(it.second==1 && t_1.find(it.first)==t_1.end())
                ans.push_back(it.first);
        }
        return ans;
    }
};
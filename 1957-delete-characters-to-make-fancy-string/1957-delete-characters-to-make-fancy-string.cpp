class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        if(n<=2)
            return s;
        string ans="";
        ans+=s[0];
        ans+=s[1];
        int index=1;
        for(int i=2;i<n;i++){
            if(s[i]!=ans[index] || s[i]!=ans[index-1])
                ans+=s[i],index++;
        }
        return ans;
    }
};
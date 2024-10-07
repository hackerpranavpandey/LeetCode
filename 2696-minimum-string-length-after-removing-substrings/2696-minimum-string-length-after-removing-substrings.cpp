class Solution {
private:
    string remove(string s){
        int i=0;
        string ans="";
        // if i<s.size()-1 and s[i]+s[i+1]=='AB' or 'CD' then don't include
        while(i<s.size()){
            if(i<s.size()-1 && ((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')))
                i++;
            else
                ans+=s[i];
            i++;
        }
        return ans;
    }
public:
    int minLength(string s) {
        // continuously remove till get the same string from the function
        string s1;
        while(true){
            s1=remove(s);
            if(s1==s)
                break;
            s=s1;
        }
        return s1.size();
    }
};
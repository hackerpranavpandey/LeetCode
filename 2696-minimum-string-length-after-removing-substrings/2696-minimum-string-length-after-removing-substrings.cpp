class Solution {
private:
    string remove(string s){
        int i=0;
        string ans="";
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
        string s1=remove(s);
        while(true){
            if(s1==remove(s1))
                break;
            else
                s1=remove(s1);
        }
        return s1.size();
    }
};
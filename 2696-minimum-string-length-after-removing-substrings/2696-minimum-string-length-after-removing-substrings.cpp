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
        // another solution is use stack
        // string s1;
        // while(true){
        //     s1=remove(s);
        //     if(s1==s)
        //         break;
        //     s=s1;
        // }
        // return s1.size();
        stack<char> s_t;
        s_t.push(s[0]);
        int n=s.size(),i=1;
        while(i<n){
            if(!s_t.empty() && s[i]=='B' && s_t.top()=='A')
                s_t.pop();
            else if(!s_t.empty() && s[i]=='D' && s_t.top()=='C')
                s_t.pop();
            else
                s_t.push(s[i]);
            i++;
        }
        return s_t.size();
    }
};
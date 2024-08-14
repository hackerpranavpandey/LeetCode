class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size()-1;
        while(n>=0){
            while(n>=0 && s[n]=='  '){
                 n--;   
            }
            string s_1="";
            while(n>=0 && s[n]!=' '){
                s_1+=s[n];
                n--;
            }
            reverse(s_1.begin(),s_1.end());
            if(s_1!=""){
                if(ans!="")
                    ans=ans+' '+s_1;
                else
                    ans=s_1;
            }
            while(n>=0 && s[n]==' '){
                n--;
            }
        }
        return ans;
    }
};
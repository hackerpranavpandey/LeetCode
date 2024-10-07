class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        if(n==1)
            return s;
        vector<int> index(26,0); //store the last index of each of char
        for(int i=0;i<n;i++){
            index[s[i]-'a']=i;
        }
        vector<int> present(26,0); // to track if present char is already in the stack
        stack<char> t;
        t.push(s[0]);
        present[s[0]-'a']=1;
        for(int i=1;i<n;i++){
            if(present[s[i]-'a'])
                continue;
            while(!t.empty() && s[i]<t.top() && index[t.top()-'a']>i){
                present[t.top()-'a']=0;
                t.pop();
            }
            t.push(s[i]);
            present[s[i]-'a']=1;
        }
        string ans="";
        while(!t.empty()){
            ans=t.top()+ans;
            t.pop();
        }
        return ans;
    }
};
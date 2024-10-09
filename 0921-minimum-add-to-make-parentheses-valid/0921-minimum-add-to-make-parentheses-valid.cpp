class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<char> s_t;
        for(char c:s){
            if(c=='(')
                s_t.push(c);
            else if(!s_t.empty())
                s_t.pop();
            else
                ans+=1;
        }
        ans+=s_t.size();
        return ans;
    }
};
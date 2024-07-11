class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> paranthesis_index;
        string ans="";
        for(char c:s){
            if(c=='('){
                paranthesis_index.push(ans.size());
            }
            else if(c==')'){
                // get the index of start of '(' of present ')'
                int start=paranthesis_index.top();
                paranthesis_index.pop();
                // reverse
                reverse(ans.begin()+start,ans.end());
            }
            else
                ans+=c;
        }
        return ans;
    }
};
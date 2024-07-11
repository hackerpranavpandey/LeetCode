class Solution {
public:
    string reverseParentheses(string s) {
        // stack<int> paranthesis_index;
        // string ans="";
        // for(char c:s){
        //     if(c=='('){
        //         paranthesis_index.push(ans.size());
        //     }
        //     else if(c==')'){
        //         // get the index of start of '(' of present ')'
        //         int start=paranthesis_index.top();
        //         paranthesis_index.pop();
        //         // reverse
        //         reverse(ans.begin()+start,ans.end());
        //     }
        //     else
        //         ans+=c;
        // }
        // return ans;
        // above is best way to solve this
        int n_b=0;  // find number of bracket
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                n_b++;
        }
        vector<int> b_i(n_b,0);   // index of all bracket '('
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                b_i[j]=i;
                j++;
            }
            else if(s[i]==')'){
                j--;
                reverse(s.begin()+b_i[j]+1,s.begin()+i);  // do not include beacket
            }
        }
        string ans="";
        for(char c:s){
            // add all char which si not bracket
            if(c!='(' && c!=')')
                ans+=c;
        }
        return ans;
    }
};
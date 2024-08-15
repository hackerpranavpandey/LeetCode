class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(char c:s) {
            if(c=='(' || c=='[' || c=='{')
                t.push(c);
            // kuch nikalne se pehle ye check karo ki stack khali to nhi hai
            else{
                if(t.empty())
                        return false;
                if(c==')'){  
                    if(t.top()!='(')
                        return false;
                    t.pop();
                }
                else if(c==']'){
                    if(t.top()!='[')
                        return false;
                    t.pop();
                }
                else {
                    if(t.top()!='{')
                        return false;
                    t.pop();
                }
            }
        }
        if(t.size()!=0)
            return false;
        return true;
    }
};
class Solution {
private:
    bool performOperation(string t,char operation){
        if(operation=='!')
            return t=="f";
        else if(operation=='|'){
            for(char c:t){
                if(c == 't')
                    return true;
            }
            return false;;
        }
        else{
            for(char c:t){
                if(c == 'f')
                    return false;
            }
            return true;
        }
    }
public:
    bool parseBoolExpr(string expression) {
        // maintain two different stack for optr and operand
        // whnever a closing bracket is there then perform operation and at last pop
        stack<char> opr;
        stack<char> operand;
        int n=expression.size();
        for(int i=0;i<n;i++){
            if(expression[i]=='&' || expression[i]=='!' || expression[i]=='|'){
                opr.push(expression[i]);
            }
            if(expression[i]=='(')
                operand.push(expression[i]);
            else if(expression[i]==')'){
                string t="";
                while(operand.top()!='('){
                    t+=operand.top();
                    operand.pop();
                }
                operand.pop();
                char operation=opr.top();
                opr.pop();
                bool ans=performOperation(t,operation);
                ans == true ? operand.push('t') : operand.push('f');
            }
            else if(expression[i]=='t' || expression[i]=='f')
                operand.push(expression[i]);
        }
        return operand.top() == 't';
    }
};
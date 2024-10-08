class Solution {
public:
    int minSwaps(string s) {
        // using stack is the best way in this question
        // so the idea is same as valid parenthesis problem
        // if there is opening bracket push it into stack
        // but for closing bracket check if there is opening bracket before
        // if not then add 1 to ans for case of present just pop it
        // at the end return swap+1/2
        int swap=0;
        stack<char> s_t;
        for(char c:s){
            if(c=='[')
                s_t.push(c);
            else{
                if(!s_t.empty())
                    s_t.pop();
                else
                    swap++;
            }
        }
        return (swap+1)/2;
    }
};
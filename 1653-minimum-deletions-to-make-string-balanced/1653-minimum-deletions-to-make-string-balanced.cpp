class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n_deletion=0;
        // pehle sare a phir sare b chahiye
        for(char c:s){
            // agar b aa gaya tab uske baad a nhi aana chahiye dono me se ek ko delete karna hoga
            if(!st.empty() && st.top()=='b' && c=='a'){  // agar stack ke top pe a hai aur stack khali nhi hai aur abhi b hai tab delete karo top ko
                st.pop();
                n_deletion++;
            }
            else{
                st.push(c);
            }
        }
        return n_deletion;
    }
};
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char c_1,c_2;
        int max_1,max_2;
        max_1=max(x,y);
        if(x>y){
            c_1='a';
            c_2='b';
            max_2=y;
        }
        else{
            c_1='b';
            c_2='a';
            max_2=x;
        }
        stack<char> st;
        st.push(s[0]);
        int n=s.size();
        int max_sum=0;
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()==c_1 && s[i]==c_2){
                max_sum+=max_1;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        if(st.size()<2)
            return max_sum;
        string remaining;
        while(!st.empty()){
            remaining+=st.top();
            st.pop();
        }
        reverse(remaining.begin(),remaining.end());
        for(char c:remaining){
            if(!st.empty() && st.top()==c_2 && c==c_1){
                max_sum+=max_2;
                st.pop();
            }
            else
               st.push(c);
        }
        return max_sum;
    }
};
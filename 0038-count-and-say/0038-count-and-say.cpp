class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        int i=1;
        while(i<n) {
            string t_rle="";
            char t=ans[0];
            int j=0;
            for(char c:ans){
                if(c==t) j++;
                else {
                    t_rle+=to_string(j),t_rle+=t;
                    t=c,j=1;
                }
            }
            t_rle+=to_string(j),t_rle+=t;
            ans=t_rle,i++;
        }
        return ans;
    }
};
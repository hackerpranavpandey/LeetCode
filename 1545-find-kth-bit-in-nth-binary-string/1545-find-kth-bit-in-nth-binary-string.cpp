class Solution {
private:
    string invert(string& s){
        string t="";
        for(char c:s){
            if(c=='0')
                t+='1';
            else
                t+='0';
        }
        return t;
    }
public:
    char findKthBit(int n, int k) {
        string prev="0";
        string curr="0";
        if(n==1)
            return prev[0];
        for(int i=0;i<n;i++){
            string t=invert(prev);
            reverse(t.begin(),t.end());
            curr=(prev+ '1') + t;
            prev=curr;
        }
        return curr[k-1];
    }
};
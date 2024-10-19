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
        // string S1="0";
        // if(n==1)
        //     return S1[0];
        // for(int i=0;i<n;i++){
        //     string t=invert(prev);
        //     reverse(t.begin(),t.end());
        //     curr=(prev+ '1') + t;
        //     prev=curr;
        // }
        // return curr[k-1];
        if(n == 1)
            return '0';
        int len=1 << n;
        if(k == len/2)
            return '1';
        else if(k < len/2)
            return findKthBit(n-1, k);
        else{
            int kBit = findKthBit(n-1, len-k);
            return (kBit == '0') ? '1' : '0';
        }
    }
};
class Solution {
public:
    int getLucky(string s, int k) {
        string ans="";
        for(char c:s){
            int index=(c-'a')+1;
            ans+=to_string(index);
        }
        while(k>0){
            int num=0;
            for(char c:ans){
                num+=(c-'0');
            }
            ans=to_string(num);
            k--;
        }
        return stoi(ans);
    }
};
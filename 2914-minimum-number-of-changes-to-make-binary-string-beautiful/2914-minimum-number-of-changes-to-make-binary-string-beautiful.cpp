class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int index=0;
        while(index<s.size()){
            if(s[index]!=s[index+1])
                ans+=1;
            index+=2;
        }
        return ans;
    }
};
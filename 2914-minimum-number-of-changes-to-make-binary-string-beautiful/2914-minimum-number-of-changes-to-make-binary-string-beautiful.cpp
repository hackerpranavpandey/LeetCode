class Solution {
public:
    int minChanges(string s) {
        // just simple logic take substring of size 2 if both are different then need 1 changes
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
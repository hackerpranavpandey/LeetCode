class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int t1=0,t2=0;
        while(t1<str1.size() && t2<str2.size()){
            if(str1[t1]==str2[t2])
                t1++,t2++;
            else if((str1[t1]=='z' && str2[t2]=='a') || (str2[t2]-str1[t1])==1)
                t1++,t2++;
            else
                t1++;
        }
        return t2==str2.size();
    }
};
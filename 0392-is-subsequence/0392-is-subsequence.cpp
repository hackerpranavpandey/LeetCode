class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index1=0,index2=0;
        while(index2<t.size() && index1<s.size()){
            if(s[index1]==t[index2])
                index2++,index1++;
            else
                index2++;
        }
        return index1==s.size();
    }
};
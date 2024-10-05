class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // so this problem is similar to checking that for each substring of size as s1
        // in s2 if there is anagram of s1
        // so simple just make a window of size as s1 in s2
        // now check that it is anagram of s1
        // continue this till end of the s2
        if(s2.size()<s1.size())   // case when s2 size is less then not possible
            return false;
        vector<int> freq_1(26,0),freq_2(26,0);
        for(char c:s1){
            freq_1[c-'a']+=1;
        }
        int n=s1.size();
        for(int i=0;i<n;i++){
            freq_2[s2[i]-'a']++;
        } 
        int count=0;
        for(int i=0;i<26;i++){
                if(freq_1[i]==freq_2[i])
                    count+=freq_1[i];
            }
        if(count==n)
            return true;
        for(int i=n;i<s2.size();i++){
            freq_2[s2[i]-'a']++,freq_2[s2[i-n]-'a']--,count=0;
            for(int j=0;j<26;j++){
                if(freq_1[j]==freq_2[j])
                    count+=freq_1[j];
            }
            if(count==n)
                return true;
        }
        return false;
    }
};
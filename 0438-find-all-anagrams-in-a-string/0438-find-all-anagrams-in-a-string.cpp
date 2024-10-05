class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // this question is similar to making the window size of n
        // then checking that is that substring anagram of p
        // and then add the first index of that to the ans vector
        // each time freq_2 keeps only the frequency of characters in the window
        if(p.size()>s.size())
            return {};
        vector<int> freq_1(26,0),freq_2(26,0);
        vector<int> ans;
        for(char c:p){
            freq_1[c-'a']++;
        }
        int n=p.size();
        for(int i=0;i<n;i++){
            freq_2[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(freq_1[i]==freq_2[i])
                count+=freq_1[i];
        }
        if(count==n)
            ans.push_back(0);
        for(int i=n;i<s.size();i++){
            freq_2[s[i-n]-'a']--,freq_2[s[i]-'a']++;
            count=0;
            for(int i=0;i<26;i++){
                if(freq_1[i]==freq_2[i])
                    count+=freq_1[i];
            }
            if(count==n)
                ans.push_back(i-n+1);
        }
        return ans;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // so this problem is similar to checking that for each substring of size as s1
        // in s2 if there is anagram of s1
        // so simple just make a window of size as s1 in s2
        // now check that it is anagram of s1
        // continue this till end of the s2
        if(s2.size()<s1.size())   // case whenn s2 size is less then not possible
            return false;
        unordered_map<char,int> mpp_1,mpp_2;
        for(char c:s1){
            mpp_1[c]+=1;
        }
        int n=s1.size();
        for(int i=0;i<n;i++){
            mpp_2[s2[i]]++;
        }
        int count=0;
        for(auto it:mpp_1){
                if(mpp_1[it.first]==mpp_2[it.first])
                    count+=it.second;
            }
        if(count==n)
            return true;
        for(int i=n;i<s2.size();i++){
            mpp_2[s2[i]]++,mpp_2[s2[i-n]]--,count=0;
            for(auto it:mpp_1){
                if(mpp_1[it.first]==mpp_2[it.first])
                    count+=it.second;
            }
            if(count==n)
                return true;
        }
        return false;
    }
};
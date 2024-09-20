class Solution {
private:
    bool is_palindrome(string s){
        int n=s.size();
        for(int i=0;i<=n/2;i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        // below is good approach but it exceeds the time limit
        // simply check the last index where from 0 to that index is a palindrome
        // then after that add the remaining to the start of ans
        // then at last add at the end
        // if(s.size()<=1)
        //     return s;
        // if(is_palindrome(s))
        //     return s;
        // int index=0;
        // for(int i=s.size()-1;i>0;i--){
        //     if(is_palindrome(s.substr(0,i+1))){
        //         index=i;
        //         break;
        //     }
        // }
        // string ans="";
        // for(int i=index+1;i<s.size();i++){
        //     ans=s[i]+ans;
        // }
        // ans+=s;
        // return ans;
        // now using KMP algorithms which is famous algorithm to find pattern
        string reversed = string(s.rbegin(),s.rend());
        string combined = s+ "#" + reversed;
        int n=combined.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int j=lps[i-1];
            while(j>0 && combined[i]!=combined[j]){
                j=lps[j-1];
            }
            if(combined[i]==combined[j])
                j++;
            lps[i]=j;
        }
        int p_l=lps[n-1];
        string to_add=s.substr(p_l);
        reverse(to_add.begin(),to_add.end());
        return to_add+s;
    }
};
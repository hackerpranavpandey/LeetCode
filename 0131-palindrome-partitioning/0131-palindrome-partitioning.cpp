class Solution {
private:
    bool palindrome(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    void solve(string s,vector<vector<string>>& ans,vector<string> s_1,int index,int n){
        if(index==n){
            ans.push_back(s_1);
            return;
        }
        // so for each index call the function recursively
        for(int i=index;i<n;i++) {
            // futher partition can only be done if it is a palindrome
            if(palindrome(s.substr(index,i-index+1))){
                s_1.push_back(s.substr(index,i-index+1));
                solve(s,ans,s_1,i+1,n);
                s_1.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> s_1;
        int n=s.size();
        solve(s,ans,s_1,0,n);
        return ans;
    }
};
class Solution {
private:
    void solve(int t,int n,vector<int>& ans){
        if(t>n)
            return;
        ans.push_back(t);
        solve(t*10,n,ans);
        for(int i=1;i<=9;i++){
            solve(t*10+i,n,ans);   
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        // actually very simple when think of recursion
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);   
        }
        return ans;
    }
};
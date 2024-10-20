class Solution {
private:
    
    void dfs(int i,vector<vector<int>>& child,string &s, string &traversed,int &count,vector<pair<int,int>> &subs){
        int t=count;
        for(int t2:child[i]){
            dfs(t2,child,s,traversed,count,subs);
        }
        traversed[2*count+1]=s[i];
        subs[i]={t,count++};
    }
    
    vector<int> manacherOdd(string s){
        int n=s.size();
        s="$"+s+'^';
        vector<int> h(n+2);
        int l=1,r=1;
        for(int i=1;i<=n;i++){
            h[i]=max(0,min(r-i,h[l+r-i]));
            while(s[i-h[i]]==s[i+h[i]]){
                h[i]++;
            }
            if(i+h[i]>r)
                l=i-h[i],r=i+h[i];
        }
        return vector<int>(h.begin()+1,h.end()-1);
    }
    
    // bool isPalindrome(string s){
    //     string t2=s;
    //     reverse(t2.begin(),t2.end());
    //     return s==t2;
    // }
    // first call for all child the add s[x] to dfsStr
    // void dfs(string& dfsStr, vector<vector<int>>& child,int x,string& s){
    //     for(int t:child[x]){
    //         dfs(dfsStr,child,t,s);
    //     }
    //     dfsStr+=s[x];
    //     return;
    // }
    
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n=parent.size(),count=0;
        vector<vector<int>> child(n);
        for(int i=1;i<n;i++){
                child[parent[i]].push_back(i);
        }
        vector<bool> ans(n,false);
        string traversed(2*n+1,'#');
        vector<pair<int,int>> subs(n);
        dfs(0,child,s,traversed,count,subs);
        // string dfsStr;
        // for(int i=0;i<n;i++){
        //     dfsStr="";
        //     dfs(dfsStr,child,i,s);
        //     isPalindrome(dfsStr) == true ? ans.push_back(true) : ans.push_back(false);
        // }
        auto d=manacherOdd(traversed);
        for(int i=0;i<n;i++){
            auto &[l,r]=subs[i];
            int len=r-l+1;
            ans[i]=d[l+r+1]-1>=len;
        }
        return ans;
    }
};
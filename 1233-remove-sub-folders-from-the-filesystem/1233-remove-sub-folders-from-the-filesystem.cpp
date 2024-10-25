class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        int n=folder.size();
        ans.push_back(folder[0]);
        string currFolder="";
        currFolder=ans[0];
        for(int i=1;i<n;i++){
            int cmp=currFolder.size();
            if(folder[i].size() < cmp)
                ans.push_back(folder[i]),currFolder=folder[i];
            else if(folder[i].size() == cmp && folder[i]!=currFolder)
                ans.push_back(folder[i]),currFolder=folder[i];
            else if((folder[i].substr(0,cmp)!=currFolder) || (folder[i].substr(0,cmp)==currFolder && folder[i][cmp]!='/'))
                ans.push_back(folder[i]),currFolder=folder[i];
        }
        return ans;
    }
};
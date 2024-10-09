class Solution {
public:
    string oddString(vector<string>& words) {
        vector<vector<int>> v1;
        int n=words.size(),m=words[0].size();
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=1;j<m;j++){
                v.push_back((int)(words[i][j]-words[i][j-1]));
            }
            v1.push_back(v);
        }
        if(v1[0]!=v1[1] && v1[0]!=v1[2])   // here in this case v1[0] is different so is words[0]
             return words[0];
        for(int i=1;i<n;i++){
            if(v1[i]!=v1[0])
                return words[i];
        }
        return words[0];
    }
};
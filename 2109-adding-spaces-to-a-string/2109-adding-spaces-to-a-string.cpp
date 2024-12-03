class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int index=0;
        int i=0;
        while(index!=s.size()){
            if(i<spaces.size() && index==spaces[i]){
                ans+=' ';
                i++;
            }
            ans+=s[index];
            index++;
        }
        return ans;
    }
};
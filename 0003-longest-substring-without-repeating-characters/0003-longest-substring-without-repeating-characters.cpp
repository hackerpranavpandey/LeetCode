class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0;
        int n=s.size();
        while(i<n){
            unordered_set<char> element;
            int start=i;
            while(start<n){
                if(element.find(s[start])==element.end()){
                    element.insert(s[start]);
                    start++;
                }
                else
                    break;
            }
            ans=max(ans,start-i);
            i++;
        }
        return ans;
    }
};
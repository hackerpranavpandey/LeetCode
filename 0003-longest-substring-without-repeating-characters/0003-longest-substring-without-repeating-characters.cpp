class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int ans=0;
        // int i=0;
        // int n=s.size();
        // while(i<n){
        //     unordered_set<char> element;
        //     int start=i;
        //     while(start<n){
        //         if(element.find(s[start])==element.end()){
        //             element.insert(s[start]);
        //             start++;
        //         }
        //         else
        //             break;
        //     }
        //     ans=max(ans,start-i);
        //     i++;
        // }
        // return ans;
        vector<int> mpp(256,-1);
        int left=0,right=0;
        int n=s.size();
        int ans=0;
        while(right<n){
            if(mpp[s[right]]!=-1)
                left=max(mpp[s[right]]+1,left);
            mpp[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
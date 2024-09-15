class Solution {
public:
    int findTheLongestSubstring(string s) {
        // int ans=0;
        // int n=s.size();
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> freq;
        //     for(int j=i;j<n;j++){
        //         if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
        //             freq[s[j]]++;
        //         bool possible=true;
        //         for(auto it:freq){
        //             if(it.second%2!=0)
        //                 possible=false;
        //         }
        //         if(possible && (j-i+1)>ans)
        //             ans=(j-i+1);
        //      }
        // }
        // return ans;
        // above code is fine but it takes O(5*n^2) time complexity time but can be optimized
        // so need to use the concept of the bitmask where the concept used is very simple
        // saw the video on youtube of codewithMIK
        // so the concpet of current state and its last time occurance index matters
        unordered_map<string,int> mpp;
        string current_state="00000";
        int ans=0,i=0;
        mpp[current_state]=-1;
        for(char c:s){
            if(c=='a'){
                int t=(current_state[0]-'0');
                t+=1,t%=2;
                current_state[0]=static_cast<char>(t+'0');
            }
            else if(c=='e'){
                int t=(current_state[1]-'0');
                t+=1,t%=2;
                current_state[1]=static_cast<char>(t+'0');
            }
            else if(c=='i'){
                int t=(current_state[2]-'0');
                t+=1,t%=2;
                current_state[2]=static_cast<char>(t+'0');
            }
            else if(c=='o'){
                int t=(current_state[3]-'0');
                t+=1,t%=2;
                current_state[3]=static_cast<char>(t+'0');
            }
            else if(c=='u'){
                int t=(current_state[4]-'0');
                t+=1,t%=2;
                current_state[4]=static_cast<char>(t+'0');
            }
            if(mpp.find(current_state)!=mpp.end())
                ans=max(ans,i-mpp[current_state]);
            else
                mpp[current_state]=i;
            i++;
        }
        return ans;
    }
};
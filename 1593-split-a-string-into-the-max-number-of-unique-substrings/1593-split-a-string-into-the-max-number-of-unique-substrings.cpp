class Solution {
private:
    int maxSplit(string& s,int t, unordered_set<string>& splitString){
        if(t==s.size())
            return 0;
        int ans=0;
        for(int last=t+1; last<= s.size(); last++){
           if(!splitString.count(s.substr(t,last-t))){
               splitString.insert(s.substr(t,last-t));
               ans=max(ans,1+maxSplit(s,last,splitString));
               splitString.erase(s.substr(t,last-t));
           }
        }
        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        // cannot do it this way there are few issues with the code
        // int n=s.size();
        // unordered_set<string> t;
        // int index=0,ans=0;
        // while(index<n){
        //     int count=1;
        //     while(index+count<n){
        //         if(!t.count(s.substr(index,count)) && !t.count(s.substr(index+count,n-count)) && s.substr(index,count!=s.substr(index+count,n-count)){
        //             ans++;
        //             t.insert(s.substr(index,count));  
        //             break;
        //         }
        //         else
        //             count++;
        //     }
        //     index+=count;
        // }
        // return ans+1;
        unordered_set<string> splitString;
        int ans= maxSplit(s,0,splitString);
        return ans;
    }
};
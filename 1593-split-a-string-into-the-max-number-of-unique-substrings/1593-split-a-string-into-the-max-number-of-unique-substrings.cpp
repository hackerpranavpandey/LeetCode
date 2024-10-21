class Solution {
private:
    int maxSplit(string& s, int index, unordered_set<string>& unique){
        if(index==s.size())
            return 0;
        int ans=0;
        for(int last=index+1; last<=s.size() ; last++){
            if(unique.find(s.substr(index,last-index))==unique.end()){
                unique.insert(s.substr(index,last-index));
                ans=max(ans,1+maxSplit(s,last,unique));
                unique.erase(s.substr(index,last-index));
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
        unordered_set<string> unique;
        return maxSplit(s,0,unique);
    }
};
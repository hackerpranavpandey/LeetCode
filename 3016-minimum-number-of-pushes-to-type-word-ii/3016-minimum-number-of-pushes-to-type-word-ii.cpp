class Solution {
public:
    int minimumPushes(string word) {
        // first compute the frequency of each char in a mmap
        unordered_map<char,int> freq_count;
        for(char c:word){
            freq_count[c]++;
        }
        // then sort them after storing in a vector
        // then simple for first 8 simply one push is needed
        // for the next 8 two and so on 
        // here 1,*,0,# are not being considered for using as a push key
        vector<int> freq;
        for(auto it:freq_count){
            freq.push_back(it.second);
        }
        // sort in reverse order
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        int current_push=0;
        for(int i=0;i<freq.size();i++){
            // after each time first 8 for current push has been used then update the current_push value 
            // this will work here for 0 also so started for current_push with 0
            if(i%8==0){
                current_push++;
                ans+=(freq[i]*current_push);
            }
            else{
                ans+=(freq[i]*current_push);
            }
        }
        return ans;
    }
};
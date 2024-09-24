class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;
        for(int arr:arr1){
            while(arr>0){
                prefix.emplace(to_string(arr));
                arr/=10;
            }
        }
        int ans=0;
        for(int arr:arr2){
            while(arr>0){
                string curr=to_string(arr);
                if(prefix.find(curr)!=prefix.end()){
                    if(curr.size()>ans)
                        ans=curr.size();
                    break;
                }
                arr/=10;
            }
        }
        return ans;
    }
};
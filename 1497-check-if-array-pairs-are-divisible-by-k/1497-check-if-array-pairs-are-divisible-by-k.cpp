class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // algorithm below works only for positive values
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     arr[i]%=k;
        // }
        // int start=0,end=n-1;
        // while(start<end){
        //     if((arr[start]+arr[end])%k!=0)
        //         return false;
        //     start++,end--;
        // }
        // return true;
        // for negative cases just do (i%k+k)%k
        unordered_map<int,int> remainder_count;
        for(int t:arr) remainder_count[(t%k+k)%k]++;
        for(auto it: remainder_count){
            if(it.first==0){
                if(it.second%2!=0)
                    return false;
            }
            else if(remainder_count[k-it.first]!=remainder_count[it.first])
                return false;
        }
        return true;
    }
};
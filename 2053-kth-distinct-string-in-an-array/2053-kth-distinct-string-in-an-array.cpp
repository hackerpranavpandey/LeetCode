class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        for(string s:arr){
            mpp[s]++;
        }
        int i=0;
        for(string s:arr){
            if(mpp[s]==1){
                i++;
                if(i==k)
                    return s;
            }
        }
        return "";
    }
};
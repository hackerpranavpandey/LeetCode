class Solution {
private:
    int set_bits(int num){
        int count=0;
        while(num>0){
            if(num&1)
                count++;
            num=num>>1;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        // just make a vector pair and then store the number of set bit, number itself and sort
        vector<pair<int,int>> t;
        for(int i=0;i<arr.size();i++){
            t.push_back({set_bits(arr[i]),arr[i]});
        }
        sort(t.begin(),t.end());
        for(int i=0;i<arr.size();i++){
            arr[i]=t[i].second;
        }
        return arr;
    }
};
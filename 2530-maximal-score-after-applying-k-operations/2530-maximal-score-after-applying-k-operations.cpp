class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // damn simple just use priority queue
        long long ans=0;
        priority_queue<int> storeNum;
        int n=nums.size();
        for(auto& num:nums){
            storeNum.push(num);
        }
        while(k>0){
            int curr=storeNum.top();
            storeNum.pop();
            ans+=curr;
            curr=ceil((double)curr/(double)3);
            storeNum.push(curr);
            k--;
        }
        return ans;
    }
};
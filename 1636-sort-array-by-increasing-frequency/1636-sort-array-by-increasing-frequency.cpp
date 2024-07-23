class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq_count;
        for(int num:nums){
            freq_count[num]+=1;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(freq_count[b]>freq_count[a])
                return true;
            else if(freq_count[a]==freq_count[b])
                return a>b;
            else
                return false;
        });
        return nums;
    }
};
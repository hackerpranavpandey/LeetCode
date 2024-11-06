class Solution {
private:
    int set_bit(int n){
        int ans=0;
        while(n>0){
            if(n&1)  ans++;
            n=n>>1;
        }
        return ans;
    }
    bool is_sorted(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])
                return false;
        }
        return true;
    }
public:
    bool canSortArray(vector<int>& nums) {
        // store set bit for O(1) access
        // then check if it is not sorted if it is possible to swap then do repeat 
        // if it is not sorted and no swap possible then just return false
        unordered_map<int,int> t;
        for(int &num:nums){
            t[num]=set_bit(num);
        }
        while(!is_sorted(nums)){
            bool find=false;
            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1] && t[nums[i]]==t[nums[i-1]]){
                    swap(nums[i],nums[i-1]);  
                    find=true;
                }
            }
            if(!find)
                return false;
        }
        return true;
    }
};
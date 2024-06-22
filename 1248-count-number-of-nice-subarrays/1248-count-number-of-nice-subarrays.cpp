class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int,int> odd_count;
       int odd=0;
       int ans=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]%2==1)
               odd++;
           if(odd==k)
               ans+=1;
           if(odd_count.find(odd-k)!=odd_count.end())
               ans+=odd_count[odd-k];
           odd_count[odd]++;
       }
       return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // idea using sorting
        // if(nums.size()==0)
        //     return 0;
        // sort(nums.begin(),nums.end());
        // int start=nums[0];
        // int ans=1;
        // int cnt=1;
        // int i=1;
        // while(i<nums.size()){
        //     if(nums[i]==(start+1)){
        //          cnt++;
        //          start=nums[i];
        //     }
        //     else if((nums[i]-1)>start){
        //         ans=max(ans,cnt);
        //         start=nums[i];
        //         cnt=1;
        //     }
        //     i++;
        // }
        // ans=max(ans,cnt);
        // return ans;
        unordered_set<int> sequence;
        for(int num:nums){
            sequence.insert(num);
        }
        int ans=0;
        for(auto it:sequence){
            if(sequence.find(it-1)==sequence.end()){
                int cnt=1;
                int value=it+1;
                while(sequence.find(value)!=sequence.end()){
                    value++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
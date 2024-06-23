class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int ans=0;
        // int i=0,j=0;
        // int max_found=nums[0],min_found=nums[0];
        // int n=nums.size();
        // while(j<n){
        //     max_found=max(max_found,nums[j]);
        //     min_found=min(min_found,nums[j]);
        //     if(abs(max_found-min_found)>limit){
        //         max_found=nums[j];
        //         min_found=nums[j];
        //         i=j;
        //         j++;
        //     }
        //     else
        //         j++;
        //     ans=max(ans,j-i);
        // }
        // return ans;
        // problem ye hai code me ki directly jump nhi kar sate i se j tak
        // beech ke element me koi aisa bhi ho sakta hai jisse aur longest subarray possible ho
        // so heap ki jarurat hai hi
        // wo bhi min aur max dono
        // jaise 1,3,7,6,4,0 if limit is 3
        // then ye 1 se directly 6 pe jump kar jaega 
        // but 3 pe karna chahiye tha
        priority_queue<pair<int,int>,vector<pair<int,int>>> maxpq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minpq;
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            minpq.push({nums[j],j});
            maxpq.push({nums[j],j});
            while(maxpq.top().first-minpq.top().first>limit){
                i=min(maxpq.top().second,minpq.top().second)+1;
                while(maxpq.top().second < i){
                    maxpq.pop();
                }
                while(minpq.top().second < i){
                    minpq.pop();
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
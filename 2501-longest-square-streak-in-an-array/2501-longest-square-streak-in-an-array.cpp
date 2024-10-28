class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // so below are two ways to do this
        // one is sinmply generate all possible subsequences and check
        // another is since maximum possible is 5 so for each element square it four times
        // and check if found continue update ans also if it exceeds integer then break
        // int ans=-1;
        // int n=nums.size();
        // long long t=pow(2,n);
        // for(long long i=1;i<t;i++){
        //     vector<int> subSequence;
        //     for(int j=0;j<n;j++){
        //         if(i & (1<<j))
        //             subSequence.push_back(nums[j]);
        //     }
        //     sort(subSequence.begin(),subSequence.end());
        //     bool t1=true;
        //     for(int t=1;t<subSequence.size();t++){
        //         if(subSequence[t]!=pow(subSequence[t-1],2)){
        //             t1=false;
        //             break;
        //         }
        //     }
        //     int t=subSequence.size();
        //     if(t>=2 && t1)
        //         ans=max(ans,t);
        // }
        // return ans;
        unordered_set<int> t;
        for(int &num:nums){
            t.insert(num);
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            long long curr=nums[i];
            for(int j=1;j<=4;j++){
                curr=pow(curr,2);
                if(curr>INT_MAX)
                    break;
                else if(t.count(curr))
                    ans=max(ans,j+1);
                else
                    break;
            }
        }
        return ans;
    }
};
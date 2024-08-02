class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // since we know the size of subarray will be same as number of ones
        // so for wach such subarray compute number of swap required
        // it will be equal to number of zerosfor in that subarray
        // below code is logically correct but exceeds time limit
        // int n=nums.size();
        // int num_one=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==1)
        //         num_one++;
        // }
        // if(num_one==n || num_one==0)
        //     return 0;
        // int i=0;
        // int ans=INT_MAX;
        // while(i<n){
        //     int swap=0;
        //     for(int start=i;start<(i+num_one);start++){
        //         if(start>=n){
        //             if(nums[start-n]==0)
        //                 swap++;
        //         }     
        //         else if(nums[start]==0)
        //             swap++;
        //     }
        //     ans=min(ans,swap);
        //     i+=1;
        // }
        // return ans;
        // now to avoid time complexity issue
        // use vector to store num of zeros till that index including that index
        int n=nums.size();
        int num_one=0;
        vector<int> num_zeros(n,0); // store num of zeros
        int num_zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                num_zero++;
            else
                num_one++;
            num_zeros[i]=num_zero;
        }
        // no swap needed
        if(num_one==n || num_one==0)
            return 0;
        int ans=num_zeros[num_one-1]; // first subarray
        for(int i=1;i<n;i++){
            int end_pos=i+num_one-1;
            int swap=0;
            if(end_pos<n)
                swap=num_zeros[end_pos]-num_zeros[i-1];
            // since it is circular need to start till inex n-1
            else{
                end_pos-=n;
                swap=(num_zeros[n-1]-num_zeros[i-1])+num_zeros[end_pos];
            }
            ans=min(ans,swap);
        }
        return ans;
    }
};
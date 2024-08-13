class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int> v_1;
        //                 v_1.push_back(nums[i]),v_1.push_back(nums[j]),v_1.push_back(nums[k]);
        //                 ans.push_back(v_1);
        //             }
        //         }
        //     }
        // }
        // return ans;
        // but above algorithm will not work for all cases
        // since it wil store duplicates too
        // so to use only distinct elements use subarray
        // so sort after checking if the sum comes to be 0
        // then insert it into set
        // set<vector<int>> distinct;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int> sub_array;
        //         sub_array.push_back(nums[i]),sub_array.push_back(nums[j]),sub_array.push_back(nums[k]);
        //                 sort(sub_array.begin(),sub_array.end());
        //                 distinct.insert(sub_array);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto it:distinct){
        //         ans.push_back(it);
        // }
        // return ans;
        // above is simple brute force algorithm but it is O(n^3)
        // now lets see some better solutions
        // unordered_map<int,int> mpp;
        // int i=0;
        // for(auto& it:nums){
        //     mpp[it]=i;
        //     i++;
        // }
        // // so for third loop simply check if the value is present or not
        // // however set has to be used again
        // int n=nums.size();
        // set<vector<int>> distinct;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int rem=-(nums[i]+nums[j]);
        //             if(mpp.find(rem)!=mpp.end() && mpp[rem]!=i && mpp[rem]!=j){
        //                 vector<int> sub_array;
        //         sub_array.push_back(nums[i]),sub_array.push_back(nums[j]),sub_array.push_back(rem);
        //                 sort(sub_array.begin(),sub_array.end());
        //                 distinct.insert(sub_array);
        //             }
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto it:distinct){
        //         ans.push_back(it);
        // }
        // return ans;
        // still above algorithm takes O(n^2) time complexity
        // don't forget to sort the entire array
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else {
                    vector<int> v_1;
                    v_1.push_back(nums[i]),v_1.push_back(nums[j]),v_1.push_back(nums[k]);
                    ans.push_back(v_1);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(k>j && nums[k]==nums[k+1]) k--;
        }
    }
        }
        return ans;
    }
};
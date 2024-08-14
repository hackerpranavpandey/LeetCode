class Solution {
    // so this function will tell me number of pairs with the distance less than dist
private:
    int count_no_pairs(vector<int>& nums,int dist){
        // since it is sorted then two pointer approach canbe used here
        int left=0;
        int right=1;
        int cnt=0;
        while(left<right && right<nums.size()){
            while((nums[right]-nums[left])>dist)
                left++;
            cnt+=right-left;
            right++;
        }
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // vector<int> norm;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         norm.push_back(abs(nums[i]-nums[j]));
        //     }
        // }
        // sort(norm.begin(),norm.end());
        // int ans=norm[k-1];
        // return ans;
        // above is simple brute force approach
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // dist can be between range 0 to max possible
        // so we can simply apply binary search
        int dist_start=0;
        int dist_end=nums[n-1]-nums[0];
        while(dist_start<=dist_end){
            int mid=(dist_start+dist_end)/2;
            int count=count_no_pairs(nums,mid);
            // this is not needed here actutally
            // if(count==k)
            //     return mid;
            if(count<k)
                dist_start=mid+1;
            else
                dist_end=mid-1;
        }
        return dist_start;
    }
};
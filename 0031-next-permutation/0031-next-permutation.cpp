class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // int n=nums.size();
        // int pos=n-1;
        // int min_index=n-1;
        // if(n==1)
        //     return;
        // while(pos>0){
        //     if(pos>0 && nums[pos]>nums[pos-1]){
        //         break;
        //     }
        //     if(nums[pos]<nums[min_index])
        //         min_index=pos;
        //     pos--;
        // }
        // // for case when sorter it is in non increasig order
        // if(pos==0){
        //     sort(nums.begin(),nums.end());
        //     return;
        // }
        // // case when then are sorted in non decreasing order
        // else if(pos==n-1){
        //     swap(nums[n-1],nums[n-2]);
        //     return;
        // }
        // else{
        //     swap(nums[pos],nums[min_index]);
        // }
        // next bada vaue nikalna hai
        // jaise 2,5,4,3,0,0,0
        // next biggest hoga 3,5,5,2,0,0
        // 3 aur 2 ko swap kardo
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        // case when it iis sorted in reverse order
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //ab index se last tak ka next sabse bada value nikalna hai
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                 swap(nums[i],nums[index]);
                break;
            }
             
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};
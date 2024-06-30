class Solution {
private:
    // the task of this function is to start from start_index in nums
    // and give l such that sum of two consecutive number remainder with 2 is r
    int maxLength(vector<int>& nums,int start_index,int r){
        int n=nums.size();
        int length=1;
        int last=nums[start_index];
        for(int i=start_index+1;i<n;i++){
            if((last+nums[i])%2==r){
                length+=1;
                last=nums[i];
            }
        }
        return length;
    }
public:
    int maximumLength(vector<int>& nums) {
        // logic is clear there can be eith remainder=0 or 1
        // below code is correct but too long
        // int n=nums.size();
        // int even_index=-1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==0){
        //         even_index=i;
        //         break;
        //     }
        // }
        // int length_1=0;
        // if(even_index==-1)
        //     return n;
        // else{
        //     int l1=1;
        //     int last=nums[even_index];
        //     for(int i=even_index+1;i<n;i++){
        //         if((last+nums[i])%2==0){
        //             last=nums[i];
        //             l1+=1;
        //         }
        //     }
        //     int l2=1;
        //     last=nums[even_index];
        //     for(int i=even_index+1;i<n;i++){
        //         if((last+nums[i])%2==1){
        //             last=nums[i];
        //             l2+=1;
        //         }
        //     }
        //     length_1=max(l1,l2);
        // }
        // int odd_index=-1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==1){
        //         odd_index=i;
        //         break;
        //     }
        // }
        // int length_2=0;
        // if(odd_index==-1)
        //     return n;
        // else{
        //     int l1=1;
        //     int last=nums[odd_index];
        //     for(int i=odd_index+1;i<n;i++){
        //             if((last+nums[i])%2==0){
        //                 last=nums[i];
        //                 l1+=1;
        //         }
        //     }
        //     int l2=1;
        //     last=nums[odd_index];
        //     for(int i=odd_index+1;i<n;i++){
        //         if((last+nums[i])%2==1){
        //             last=nums[i];
        //             l2+=1;
        //         }
        //     }
        //     length_2=max(l1,l2);
        //     }
        // return max(length_1,length_2);
        int first_even=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                first_even=i;
                break;
            }
        }
        if(first_even==-1)  // all odd
            return n;
        int l_1=max(maxLength(nums,first_even,0),maxLength(nums,first_even,1));
        int first_odd=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                first_odd=i;
                break;
            }
        }
        if(first_odd==-1)  // all even
            return n;
        int l_2=max(maxLength(nums,first_odd,0),maxLength(nums,first_odd,1));
        return max(l_1,l_2);
        }
};
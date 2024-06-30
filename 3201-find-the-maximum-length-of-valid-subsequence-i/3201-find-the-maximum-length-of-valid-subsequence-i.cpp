class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int even_index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even_index=i;
                break;
            }
        }
        int length_1=0;
        if(even_index==-1)
            return n;
        else{
            int l1=1;
            int last=nums[even_index];
            for(int i=even_index+1;i<n;i++){
                if((last+nums[i])%2==0){
                    last=nums[i];
                    l1+=1;
                }
            }
            int l2=1;
            last=nums[even_index];
            for(int i=even_index+1;i<n;i++){
                if((last+nums[i])%2==1){
                    last=nums[i];
                    l2+=1;
                }
            }
            length_1=max(l1,l2);
        }
        int odd_index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                odd_index=i;
                break;
            }
        }
        int length_2=0;
        if(odd_index==-1)
            return n;
        else{
            int l1=1;
            int last=nums[odd_index];
            for(int i=odd_index+1;i<n;i++){
                    if((last+nums[i])%2==0){
                        last=nums[i];
                        l1+=1;
                }
            }
            int l2=1;
            last=nums[odd_index];
            for(int i=odd_index+1;i<n;i++){
                if((last+nums[i])%2==1){
                    last=nums[i];
                    l2+=1;
                }
            }
            length_2=max(l1,l2);
            }
        return max(length_1,length_2);
        }
};
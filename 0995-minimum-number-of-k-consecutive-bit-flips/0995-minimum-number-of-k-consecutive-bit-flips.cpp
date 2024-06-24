class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // lets code for brute force approach
        // int flip=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         if(i+k>nums.size())
        //             return -1;
        //         for(int j=i;j<i+k;j++){
        //             nums[j]=!nums[j];
        //         }
        //         flip+=1;
        //     }
        // }
        // return flip;
        // but it exceeds the time limit
        // problem aa rahi hai ki jab bhi zero aata hai phir sabko convert mat karo
        // tab koi aisa tarika khojo jisse pata chal jae ki waha se flip karna hai ya nhi
        queue<int> q;
        int flip=0;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && i>q.front()){
                q.pop();
            }
            if(q.size()%2==nums[i]){
                if(i+k>nums.size())
                    return -1;
                q.push(i+k-1);
                flip++;
            }
        }
        return flip;
    }
};
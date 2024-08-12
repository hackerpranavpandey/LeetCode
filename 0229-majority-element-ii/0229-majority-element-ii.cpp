class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // the logic is almost same as majority/2
        // but with few changes in the code
        // Boyer Moore Voting Algorithms
        int cnt_1=0;
        int cnt_2=0;
        int elem_1=INT_MIN,elem_2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // put rest all after if to else if
            if(cnt_1==0 && elem_2!=nums[i]){
                cnt_1=1;
                elem_1=nums[i];
            }
            else if(cnt_2==0 && elem_1!=nums[i]){
                cnt_2=1;
                elem_2=nums[i];
            }
            else if(elem_1==nums[i])
                cnt_1++;
            else if(elem_2==nums[i])
                cnt_2++;
            else{
                cnt_1--,cnt_2--;
            }
        }
        vector<int> ans;
        cnt_1=0,cnt_2=0;
        for(int it:nums){
            if(it==elem_1)
                cnt_1++;
            else if(it==elem_2)
                cnt_2++;
        }
        int mini=n/3 + 1;
        if(cnt_1>=mini)
            ans.push_back(elem_1);
        if(cnt_2>=mini)
            ans.push_back(elem_2);
        return ans;
    }
};
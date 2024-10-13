class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // so below is the simple brute force approach for this question guess its TLE
        // here we are first keeping all elements that we have into array allElements
        // then sort the array after this for each allElements[i] find allElements[j] such that
        // each list in nums has at least one element in range also smallest
        // vector<int> allElements;
        // int k=nums.size();
        // if(k==1 && nums[0].size()==1)
        //     return {nums[0][0],nums[0][0]};
        // for(int i=0;i<k;i++){
        //     for(int t:nums[i]){
        //         allElements.push_back(t);
        //     }
        // }
        // sort(allElements.begin(),allElements.end());
        // vector<int> ans;
        // int n=allElements.size();
        // ans.push_back(0),ans.push_back(INT_MAX);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int a=allElements[i],b=allElements[j];
        //         int find=0;
        //         for(int z=0;z<k;z++){
        //             for(int t:nums[z]){
        //                 if(t>=a && t<=b){
        //                     find++;
        //                     break;
        //                 }
        //             }
        //         }
        //         if(find==k){
        //             if((b-a)<(ans[1]-ans[0]))
        //                 ans[0]=a,ans[1]=b;
        //         }
        //     }
        // }
        // return ans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<>> pq;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            maxVal = max(maxVal, nums[i][0]);
        }
        while(pq.size() == nums.size()){
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;
            if(maxVal - minVal < rangeEnd - rangeStart){
                rangeStart=minVal;
                rangeEnd=maxVal;
            }
            if(col+1<nums[row].size()){
                int nextVal=nums[row][col+1];
                pq.push({nextVal,{row,col+1}});
                maxVal=max(maxVal,nextVal);
            }
        }
        return {rangeStart,rangeEnd};
    }
};
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // int ans=0;
        // for(int i=0;i<worker.size();i++){
        //     int work=worker[i];
        //     int max_profit=0;
        //     for(int j=0;j<difficulty.size();j++){
        //         if(difficulty[j]<=work){
        //             max_profit=max(max_profit,profit[j]);
        //         }
        //     }
        //     ans+=max_profit;
        // }
        // return ans;
        // above is a simple brute force approach with O(mn) time complexity and O(1) space complexity
        
        
        
        // now lets try to use max heap now
        int n=profit.size();
        int m=worker.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({profit[i],difficulty[i]});
        }
        int ans=0;
        sort(worker.begin(),worker.end(),greater<int>());
        int i=0;
        while(i<m && !pq.empty()){
            if(pq.top().second > worker[i]){
                pq.pop();
            }
            else{
                ans+=pq.top().first;
                i++;
            }
        }
        return ans;
            
            
            
        
        // unordered_map<int,int> mpp;
        
        // for(int i=0;i<n;i++){
        //     mpp[difficulty[i]]=profit[i];
        // }
        // sort(difficulty.begin(),difficulty.end());
        // int ans=0;
        
        // for(int i=0;i<m;i++){
        //     int low=0;
        //     int high=n-1;
        //     int max_profit=0;
        //     while(low<=high){
        //         int mid=(low+high)/2;
        //         if(difficulty[mid]>worker[i]){
        //             high=mid-1;
        //         }
        //         else{
        //             max_profit=max(max_profit,mpp[difficulty[mid]]);
        //             low=mid+1;
        //         }
        //     }
        //     ans+=max_profit;
        // }
        // return ans;
    }
};
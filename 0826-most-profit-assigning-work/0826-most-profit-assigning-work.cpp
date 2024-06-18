class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // firt brute force approach - o(mn)
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
          
        // some optimization using priority queues   
        // now lets try to use max heap now
        // int n=profit.size();
        // int m=worker.size();
        // priority_queue<pair<int,int>> pq;  // o(mlogm)
        // for(int i=0;i<n;i++){
        //     pq.push({profit[i],difficulty[i]});
        // }
        // int ans=0;
        // sort(worker.begin(),worker.end(),greater<int>());  // o(nlogn)
        // int i=0;
        // // o(mlogn)
        // while(i<m && !pq.empty()){
        //     if(pq.top().second > worker[i]){
        //         pq.pop();
        //     }
        //     else{
        //         ans+=pq.top().first;
        //         i++;
        //     }
        // }
        // return ans;
        
        // more optimized using binary search
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>> t;
        for(int i=0;i<n;i++){
            t.push_back({difficulty[i],profit[i]});
        }
        sort(t.begin(),t.end());
        // now if we apply binary seach then one issue might come
        // let's say if difficulty is 2 profi is 10 but for difficulty 1 profit is 20
        // so till each dissiculty maintain the max profit till thst index
        for(int i=1;i<n;i++){
            t[i].second=max(t[i].second,t[i-1].second);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int low=0;
            int high=n-1;
            int max_profit=0;
            while(low<=high){
                int mid=(low+high)/2;
                if(t[mid].first<=worker[i]){
                    max_profit=max(max_profit,t[mid].second);
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
                ans+=max_profit;
        }
        return ans;
    }
};
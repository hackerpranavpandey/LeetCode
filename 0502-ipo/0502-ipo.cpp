class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // unordered_map<int,int> mpp;
        // for(int i=0;i<profits.size();i++){
        //     mpp[profits[i]]=capital[i];
        // }
        // sort(profits.begin(),profits.end(),greater<int>());
        // while(k>0){
        //     bool find=false;
        //     for(int i=0;i<profits.size();i++){
        //         if(profits[i]!=-1 && mpp[profits[i]]<=w){
        //             w+=profits[i];
        //             profits[i]=-1;
        //             find=true;
        //             break;
        //         }
        //     }
        //     if(find==false)
        //         return w;
        //     k-=1;
        // }
        // return w;
        // uper wala code sahi hai but exceeds time limit
        vector<pair<int,int>> projects;
        int n=profits.size();
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }
        // ye capital ke basis pe sort kar dega
        sort(projects.begin(),projects.end());
        int current_project=0;
        // priority queue to always select maximum profit project
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            // for all index in project keep on checking if it can be done with w as capital push all 
            while(current_project<n && projects[current_project].first<=w){
                pq.emplace(projects[current_project].second);
                current_project+=1;
            }
            // if no such project found then we cannot do any more proh=ject now
            if(pq.size()==0)
                break;
            // else select maximum profit
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};
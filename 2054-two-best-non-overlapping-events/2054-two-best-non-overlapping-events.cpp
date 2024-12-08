class Solution {
private:
    // int compute(vector<vector<int>>& events,int currentTime,int eventCount,int index){
    //     // so there are two cases if there are no event done or 1
    //     // for one just pick max value out of the left
    //     // other than that if 0 then either consider present index one or not
    //     if(eventCount==1){
    //         int maxValue=0;
    //         for(vector<int> &event:events){
    //             int startTime=event[0], endTime=event[1], value=event[2];
    //             if(startTime>currentTime)
    //                 maxValue=max(maxValue,value);
    //         }
    //         return maxValue;
    //     }
    //     else{
    //         int ans=0;
    //         for(int i=index;i<events.size();i++){
    //             ans=max(ans,max(events[i][2]+compute(events,events[i][1],1,i+1),compute(events,0,0,i+1)));
    //         }
    //         return ans;
    //     }
    // }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // this recursive code is correct but it exceeds time limit
        // return compute(events,0,0,0);
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> t;
        int t2=0,ans=0;
        for(vector<int> &event:events){
            while(!t.empty() && t.top().first < event[0]){
                t2=max(t2,t.top().second);
                t.pop();
            }
            ans=max(ans,t2+event[2]);
            t.push({event[1],event[2]});
        }
        return ans;
    }
};
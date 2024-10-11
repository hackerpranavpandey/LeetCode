class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // below is brute force way of doing this question
        // int targetArrival=times[targetFriend][0];
        // sort(times.begin(),times.end());
        // int n=times.size();
        // vector<int> chairIndex(n,0);  // isme har index ke liye kab tak chair booked hai ye rahega
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=i;j++){
        //         // agar piche ke index ke chair ka leaving time abhi ke arrival se kam hai
        //         if(chairIndex[j]<=times[i][0]){
        //             // wo chair abhi ke friend ko mil jaega
        //              chairIndex[j]=times[i][1];
        //              if(times[i][0]==targetArrival)
        //                 return j;
        //               break;   
        //         }
        //     }
        // }
        // return 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> leavingChair;
        int targetArrival = times[targetFriend][0];
        sort(times.begin(),times.end());
        int nextChair=0;
        set<int> availableChair;
        for(auto time:times){
            int arrival=time[0],departure=time[1];
            while(!leavingChair.empty() && leavingChair.top().first<=arrival){
                availableChair.insert(leavingChair.top().second);
                leavingChair.pop();
            }
            int chair;
            if(!availableChair.empty()){
                chair=*availableChair.begin();
                availableChair.erase(chair);
            }
            else
                chair=nextChair++;
            if(arrival==targetArrival)
                return chair;
            leavingChair.push({departure,chair});
        }
        return 0;
    }
};
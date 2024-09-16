class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // the idea to convert each to minutes and the sort array
        // only consider the case for difference between the first and last index
        // only case for the first and last index need to be considered
        // so did correctly using own logic
        int i=0;
        for(string time:timePoints){
            if(time=="00:00")
                timePoints[i]="24:00";
            i++;
        }
        vector<int> t;
        for(int i=0;i<timePoints.size();i++){
            int hour=stoi(timePoints[i].substr(0,2));
            int min=stoi(timePoints[i].substr(3,2));
            t.push_back(60*hour+min);
        }
        sort(t.begin(),t.end());
        int ans=INT_MAX;
        for(int i=1;i<t.size();i++){
            ans=min(ans,t[i]-t[i-1]);
        }
        ans=min(ans,24*60-t[t.size()-1]+t[0]);
        return ans;
    }
};
class Solution {
private:
    static bool comp(const pair<int,string>& a,const pair<int,string>& b){
        return a.first>b.first;
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> mpp;
        int t=heights.size();
        for(int i=0;i<t;i++){
            mpp.push_back({heights[i],names[i]});
        }
        sort(mpp.begin(),mpp.end(),comp);
        for(int i=0;i<t;i++){
            names[i]=mpp[i].second;
        }
        return names;
    }
}; 
class Solution {
private:
    static bool comp(pair<int,string>& p1, pair<int,string>& p2){
        if(p1.first>p2.first)
            return true;
        else if(p1.first==p2.first)
            return p1.second < p2.second;
        else
            return false;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freqCount;
        for(string word:words){
            freqCount[word]++;
        }
        vector<pair<int,string>> wordsFreq;
        for(auto it:freqCount){
            wordsFreq.push_back({it.second,it.first});
        }
        sort(wordsFreq.begin(),wordsFreq.end(),comp);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(wordsFreq[i].second);
        }
        return ans;
    }
};
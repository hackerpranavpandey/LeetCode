class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> t;
        for(int &gift:gifts){
            t.push(gift);
        }
        long long ans=0;
        while(k>0){
            int front=t.top();
            t.pop();
            t.push(sqrt(front));
            k--;
        }
        while(!t.empty()){
            ans+=t.top();
            t.pop();
        }
        return ans;
    }
};
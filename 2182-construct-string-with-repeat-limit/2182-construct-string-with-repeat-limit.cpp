class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // just simple use map + priority_queue
        unordered_map<char,int> freq_count;
        for(char c:s){
            freq_count[c]++;
        }
        priority_queue<pair<char,int>> lexico_order;
        for(auto &it:freq_count){
            lexico_order.push({it.first,it.second});
        }
        string ans="";
        while(!lexico_order.empty()){
            pair<char,int> curr=lexico_order.top();
            lexico_order.pop();
            if(curr.second<=repeatLimit){
                for(int i=0;i<curr.second;i++){
                    ans+=curr.first;
                }
            }
            else{
                for(int i=0;i<repeatLimit;i++){
                    ans+=curr.first;
                }
                curr.second-=repeatLimit;
                // here is important step if no char is left then present is largest lexicographically possible
                if(lexico_order.empty())
                    return ans;
                pair<char,int> curr_2=lexico_order.top();
                lexico_order.pop();
                ans+=curr_2.first;
                curr_2.second-=1;
                if(curr_2.second>0)
                    lexico_order.push(curr_2);
                lexico_order.push(curr);
            }
        }
        return ans;
    }
};
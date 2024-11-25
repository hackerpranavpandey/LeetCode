class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start_state="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start_state+=to_string(board[i][j]);
            }
        }
        string target="123450";
        queue<string> t;
        t.push(start_state);
        unordered_set<string> visited;
        visited.insert(start_state);
        int ans=0;
        vector<int> dir={-1,3,1,-3};
        while(!t.empty()){
            int n=t.size();
            for(int i=0;i<n;i++){
                string curr=t.front();
                t.pop();
                if(curr==target)
                    return ans;
                int index=curr.find('0');
                for(int d:dir){
                    int new_t=index+d;
                    int col=index%3;
                    if(new_t>=0 && new_t<6 && !(d==-1 && col==0) && !(d==1 && col==2)){
                        string t2=curr;
                        swap(t2[index],t2[new_t]);
                        if(!visited.count(t2)){
                            t.push(t2);
                            visited.emplace(t2);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // somehow need to sort the index of robots based on their positions
        int n=healths.size();
        vector<int> indices(n);
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        // sort kardo robot ko position ke basis pe
        sort(indices.begin(),indices.end(),[&](int a,int b){
            return positions[a]<positions[b];
        });
        stack<int> st;
        for(int curr_index:indices){
           if(directions[curr_index]=='R')
               st.push(curr_index);
            else{
                while(!st.empty() && healths[curr_index]>0){
                    int t=st.top();
                    if(healths[curr_index]>healths[t]){
                        st.pop();
                        healths[t]=0;
                        healths[curr_index]-=1;
                    }
                    else if(healths[t]>healths[curr_index]){
                        healths[curr_index]=0;
                        healths[t]-=1;
                    }
                    else{
                        st.pop();
                        healths[curr_index]=0;
                        healths[t]=0;
                    }
                }
            }
        }
        vector<int> ans;
       for(int h:healths){
           if(h>0)
               ans.push_back(h);
        }
        return ans;
    }
};
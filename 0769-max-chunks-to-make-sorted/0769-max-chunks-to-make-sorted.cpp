class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=1;
        stack<int> st;
        int curr_max=arr[0];
        bool find=false;
        int index=0;
        while(!(st.size()==(curr_max+1) && find)){
            st.push(arr[index]);
            curr_max=max(curr_max,arr[index]);
            if(arr[index]==0)
                find=true;
            index++;
        }
        while(!st.empty()){
            st.pop();
        }
        int prev_max=curr_max;
        for(int i=index;i<n;i++){
            st.push(arr[i]);
            curr_max=max(curr_max,arr[i]);
            if(curr_max-prev_max==st.size()){
                ans++;
                prev_max=curr_max;
                while(!st.empty()){
                    st.pop();
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // brute force solution also works but using monotonic stack is better in O(n) time
        vector<int> ans(prices.begin(),prices.end());
        int n=prices.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                ans[st.top()]-=prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
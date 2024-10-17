class Solution {
public:
    int maximumSwap(int num) {
        // store index of max digit to right
        // for first from left where it is not equal to i just swap
        string t=to_string(num);
        int n=t.size();
        vector<int> maxRightIndex(n,0);
        maxRightIndex[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(t[i]>t[maxRightIndex[i+1]])
                maxRightIndex[i]=i;
            else
                maxRightIndex[i]=maxRightIndex[i+1];
        }
        for(int i=0;i<n;i++){
            if(maxRightIndex[i]!=i && t[i]!=t[maxRightIndex[i]]){
                swap(t[i],t[maxRightIndex[i]]);
                return stoi(t);
            }
        }
        return num;
    }
};
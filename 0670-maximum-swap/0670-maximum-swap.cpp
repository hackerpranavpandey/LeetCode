class Solution {
public:
    int maximumSwap(int num) {
        // store index of max digit to right
        // for first from left where it is not equal to i just swap
        string t=to_string(num);
        int n=t.size();
        vector<int> maxRightIndex(n,0);
        maxRightIndex[n-1]=n-1;
        char max=t[n-1];
        int index=n-1;
        for(int i=n-2;i>=0;i--){
            if(t[i]>max){
                max=t[i];
                index=i;
                maxRightIndex[i]=index;
            }
            else
                maxRightIndex[i]=index;
        }
        for(int i=0;i<n;i++){
            if(maxRightIndex[i]!=i && t[maxRightIndex[i]]>t[i]){
                swap(t[i],t[maxRightIndex[i]]);
                return stoi(t);
            }
        }
        return num;
    }
};
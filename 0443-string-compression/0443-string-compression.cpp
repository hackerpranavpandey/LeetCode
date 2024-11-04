class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> comp;
        int n=chars.size();
        int ans=0;
        int pos=0;
        while(pos<n){
            char t=chars[pos];
            int count=0;
            while(pos<n && chars[pos]==t){
                pos++;
                count++;
            }
            comp.push_back(t);
            if(count==1)
                ans+=1;
            else{
                ans+=(1+to_string(count).size());
                int start=comp.size();
                while(count>0){
                    comp.push_back(static_cast<char>(count%10 + '0'));
                    count/=10;
                }
                reverse(comp.begin()+start,comp.end());
            }
        }
        chars=comp;
        return ans;
    }
};
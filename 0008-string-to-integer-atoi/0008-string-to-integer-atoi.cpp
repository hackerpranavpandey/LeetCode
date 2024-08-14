class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int i=0,n=s.size();
        bool isNegative=false; // it will tell if the number is negative or not
        // ignore leading whitespace
        while(i<n && s[i]==' '){
            i++;
        }
        // check if it is negative
        if(i<n && s[i]=='-'){
            i++;
            isNegative=true;
        }
        // case for positive
        else if(s[i]=='+'){
            i++;
        }
        // now just convert to int and keep on multiplying with 10 and update
        while(i<n && isdigit(s[i])){
            int num=s[i]-'0';
            ans*=10;
            ans+=num;
            if(ans>INT_MAX){
                return isNegative?INT_MIN:INT_MAX;
            }
            i++;
        }
        if(isNegative==true) // agar negative hai tab
            ans*=-1;
        return (int)(ans);
    }
};
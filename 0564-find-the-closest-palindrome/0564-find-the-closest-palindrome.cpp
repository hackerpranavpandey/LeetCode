class Solution {
private:
    long find_palindrome(long left,bool even){
        long ans=left;
        if(!even)
            left/=10;
        while(left>0){
            int rem=left%10;
            ans=ans*10+rem;
            left=left/10;
        }
        return ans;
    }
public:
    string nearestPalindromic(string n) {
        int len=n.size();
        int index = len%2 == 0 ? len/2-1 : len/2;
        long first_half=stoll(n.substr(0,index+1));
        vector<long> palindrome;
        palindrome.push_back(find_palindrome(first_half,len%2==0));
        palindrome.push_back(find_palindrome(first_half+1,len%2==0));
        palindrome.push_back(find_palindrome(first_half-1,len%2==0));
        palindrome.push_back((long)pow(10,len-1)-1);
        palindrome.push_back((long)pow(10,len)+1);
        long diff=LONG_MAX,ans=0,num=stol(n);
        for(auto it:palindrome){
            if(it==num)
                continue;
            if(diff>abs(num-it)){
                diff=abs(num-it);
                ans=it;
            }
            else if(diff==abs(num-it))
                ans=min(ans,it);
        }
        return to_string(ans);
    }
};
class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        string ans="";
        char c=word[0];
        int index=1;
        int count=1;
        while(index<n){
            if(word[index]==c)
                count++;
            else{
                ans+=(to_string(count)+c);
                c=word[index];
                count=1;
            }
            index++;
            if(count==9 && index!=n){
                ans+=(to_string(count)+c);
                count=0;
                // if exactly 9 then it will insert extra 0 and corresponding char
                if(word[index]!=c){
                    c=word[index];
                    count=1;
                    index++;
                }
            }
        }
        ans+=(to_string(count)+c);
        return ans;
    }
};
class Solution {
public:
    string compressedString(string word) {
        // below code is correct but it has very bad readibility
        // int n=word.size();
        // string ans="";
        // char c=word[0];
        // int index=1;
        // int count=1;
        // while(index<n){
        //     if(word[index]==c)
        //         count++;
        //     else{
        //         ans+=(to_string(count)+c);
        //         c=word[index];
        //         count=1;
        //     }
        //     index++;
        //     if(count==9 && index!=n){
        //         ans+=(to_string(count)+c);
        //         count=0;
        //         // if exactly 9 then it will insert extra 0 and corresponding char
        //         if(word[index]!=c){
        //             c=word[index];
        //             count=1;
        //             index++;
        //         }
        //     }
        // }
        // ans+=(to_string(count)+c);
        // return ans;
        int n=word.size();
        string comp="";
        int pos=0;
        while(pos<n){
            int count=0;
            char current=word[pos];
            while(pos<n && count<9 && word[pos]==current){
                pos++;
                count++;
            }
            comp+=(to_string(count)+current);
        }
        return comp;
    }
};
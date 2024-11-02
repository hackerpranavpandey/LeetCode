class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();
        if(sentence[0]!=sentence[n-1] || sentence[0]==' ' || sentence[n-1]==' ')
            return false;
        int i=0;
        char last=' ';
        while(i<n){
            if(i>0 && i<=n-1 && sentence[i-1]==' ' && last!=sentence[i])
                return false;
            if(i+1<=n-1 && sentence[i+1]==' ')
                last=sentence[i];
            i++;
        }
        return true;
    }
};
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        if(searchWord.size()>sentence.size())
            return -1;
        int n1=searchWord.size();
        if(sentence.substr(0,n1)==searchWord)
            return 1;
        int index=1;
        int word_number=1;
        while(index<sentence.size()){
            if(sentence[index-1]==' ')
                word_number++;
            if(sentence[index-1]==' ' && sentence.substr(index,n1)==searchWord)
                return word_number;
            index++;
        }
        return -1;
    }
};
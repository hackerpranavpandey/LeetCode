// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
//         // lets try brute force approach first
//         // exceeds time limit
//         // int n=words.size();
//         // vector<int> ans(n,0);
//         // for(int i=0;i<n;i++){
//         //     string curr="";
//         //     int count=0;
//         //     for(char c:words[i]){
//         //         curr+=c;
//         //         for(string word:words){
//         //             int t=curr.size();
//         //             if(curr==word.substr(0,t))
//         //                 count++;
//         //         }
//         //     }
//         //     ans[i]=count;
//         // }
//         // return ans;
//         int n=words.size();
//         vector<int> ans(n,0);
//         unordered_map<string,int> mpp;
//         for(int i=0;i<n;i++){
//             string curr="";
//             int count=0;
//             for(char c:words[i]){
//                 // count for the present substring
//                 int count_2=0;
//                 curr+=c;
//                 // if already computed previously then no need to compute it again
//                 if(mpp.find(curr)!=mpp.end()){
//                     count+=mpp[curr];
//                     continue;
//                 }
//                 int t=curr.size();
//                 for(string word:words){
//                     if(curr==word.substr(0,t))
//                         count_2++;
//                 }
//                 mpp[curr]=count_2;
//                 // agar ab tak ke index tak prefix 0 hai tab aage ke liye bhi hoga hi
//                 if(count_2==0)
//                     break;
//                 count+=count_2;
//             }
//             ans[i]=count;
//         }
//         return ans;
//     }
// };
class TrieNode {
public:
    TrieNode* children[26];
    int count;

    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie and increment count for each prefix
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->count++;
        }
    }

    // Get the sum of prefix scores for a word
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            int index = c - 'a';
            node = node->children[index];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word); // Build the Trie with prefix counts
        }

        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word)); // Get prefix scores for each word
        }

        return result;
    }
};
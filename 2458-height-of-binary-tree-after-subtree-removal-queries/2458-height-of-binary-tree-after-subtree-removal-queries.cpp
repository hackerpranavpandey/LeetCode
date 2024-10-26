/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight=0;
    void traverseLeftToRight(TreeNode* node, int currentHeight){
        if(node == nullptr)
            return;
        maxHeightAfterRemoval[node->val] = currentMaxHeight;
        currentMaxHeight = max(currentMaxHeight, currentHeight);
        traverseLeftToRight(node->left, currentHeight+1);
        traverseLeftToRight(node->right, currentHeight+1);
    }
    void traverseRightToLeft(TreeNode* node, int currentHeight){
        if(node == nullptr)
            return;
        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val],currentMaxHeight);
        currentMaxHeight = max(currentMaxHeight, currentHeight);
        traverseRightToLeft(node->right, currentHeight+1);
        traverseRightToLeft(node->left, currentHeight+1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root,0);
        currentMaxHeight=0;
        traverseRightToLeft(root,0);
        int queriesCount=queries.size();
        vector<int> ans(queriesCount);
        for(int i=0;i<queriesCount;i++){
            ans[i]=maxHeightAfterRemoval[queries[i]];
        }
        return ans;
    }
};
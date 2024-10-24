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
//     // recursive way to check if two tree are identical
//     bool identicalTree(TreeNode* root1, TreeNode* root2){
//         if(!root1 && !root2)
//             return true;
//         else if((!root1 && root2) || (root1 && !root2))
//             return false;
//         else if(root1->val != root2->val)
//             return false;
//         return identicalTree(root1->left,root2->left) && identicalTree(root1->right,root2->right);
//     }
    string findIdentical(TreeNode* root,unordered_map<string,int>& tCount, vector<TreeNode*>& ans){
        if(!root)
            return "#";
        string t=to_string(root->val) + "#" + findIdentical(root->left,tCount,ans) + "#" + findIdentical(root->right,tCount,ans);
        tCount[t]++;
        if(tCount[t]==2)
            ans.push_back(root);
        return t;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> tCount;
        vector<TreeNode*> ans;
        string t_2=findIdentical(root,tCount,ans);
        return ans;
    }
};
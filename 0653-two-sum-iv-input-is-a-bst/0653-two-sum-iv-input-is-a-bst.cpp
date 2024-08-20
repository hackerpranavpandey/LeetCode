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
    void inorder(TreeNode* root,vector<int>& bst_val){
        if(!root)
            return;
        else{
            inorder(root->left,bst_val);
            bst_val.push_back(root->val);
            inorder(root->right,bst_val);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> bst_val;
        inorder(root,bst_val);
        int n=bst_val.size();
        int start=0,end=n-1;
        while(start<end){
            int sum=bst_val[start]+bst_val[end];
            if(sum==k)
                return true;
            else if(sum>k)
                end-=1;
            else
                start+=1;
        }
        return false;
    }
};
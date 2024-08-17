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
public:
    // void inorder(TreeNode* root,vector<int>& ans){
    //     if(root){
    //         inorder(root->left,ans);
    //         ans.push_back(root->val);
    //         inorder(root->right,ans);
    //     }
    // }
    vector<int> inorderTraversal(TreeNode* root){
        // vector<int> ans;
        // inorder(root,ans);
        // return ans;
        // above is recursive way to do this
        // now lets do intutively using morris traversal
        TreeNode* curr=root;
        vector<int> ans;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                // point left tree right most node to each root node
                // but specia cheking condition whether to move right or left from current node
                while(temp->right!=NULL && temp->right!=curr){
                    temp=temp->right;
                }
                // threading concept to be used here
                // when righmost node of left subtree points to null then move to leftmost tree
                if(temp->right!=curr){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    ans.push_back(curr->val);
                    temp->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
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
    void inorder(TreeNode* root,vector<int>& ans){
        if(root==NULL)
            return;
        else{
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        return ans[k-1];
        // TreeNode* curr=root;
        // int count=0;
        // int ans=-1;
        // while(curr){
        //     // case when there is no left tree
        //     if(curr->left){
        //         count++;
        //         if(count==k-1){
        //             ans=curr;
        //             break;
        //         }
        //         curr=curr->right;
        //     }
        //     else{
        //         TreeNode* temp=curr->left;
        //         while(temp->left!=NULL && temp->right!=curr){
        //             temp=temp->right;
        //         }
        //         if(temp->right==NULL){
        //             temp->right=curr;
        //             curr=curr->left;
        //         }
        //         else{
        //             count++;
        //             if(count==k-1){
        //                 ans=curr;
        //                 break;
        //             }
        //             temp->right=
        //         }
        //     }
        // }
    }
};
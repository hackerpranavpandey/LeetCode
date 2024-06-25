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
    // it will not work here
//     // return sum of right subtree
//     int SumOfRight(TreeNode* root){
//         if(root==NULL)
//             return 0;
//         int left_sum=0;
//         int right_sum=0;
//         left_sum=SumOfRight(root->left);
//         right_sum=SumOfRight(root->right);
//         return (root->val+left_sum+right_sum);
//     }
public:
    vector<int> node_val;
    unordered_map<int,int> mpp;
    void Inorder(TreeNode* root){
        if(root==NULL)
            return;
        else{
            Inorder(root->left);
            node_val.push_back(root->val);
            Inorder(root->right);
        }
    }
    void update(TreeNode* root){
        if(root==NULL)
            return;
        else{
            update(root->left);
            root->val=mpp[root->val];
            update(root->right);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        Inorder(root);
        int n=node_val.size();
        // sort(node_val.begin(),node_val.end());
        mpp[node_val[n-1]]=node_val[n-1];
        for(int i=node_val.size()-2;i>=0;i--){
            mpp[node_val[i]]=node_val[i]+mpp[node_val[i+1]];
        }
        update(root);
        return root;
    }
};
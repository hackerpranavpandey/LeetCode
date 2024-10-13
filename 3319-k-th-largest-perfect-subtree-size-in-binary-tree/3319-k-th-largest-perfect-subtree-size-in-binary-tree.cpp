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
    vector<int> perfectBinary;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if(left==right && left!=-1){
            int currentSize=left+right+1;
            perfectBinary.push_back(currentSize);
            return currentSize;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        // simple recursive based logic
        int ans=solve(root);
        sort(perfectBinary.begin(),perfectBinary.end(),greater<int>());
        if(perfectBinary.size()<k)
            return -1;
        return perfectBinary[k-1]; 
    }
};
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
    int swap_required(vector<int>& original) {
        int swaps=0;
        vector<int> v=original;
        sort(v.begin(),v.end());
        unordered_map<int,int> t;
        for(int i=0;i<original.size();i++){
            t[original[i]]=i;
        }
        for(int i=0;i<original.size();i++){
            if(original[i]!=v[i]){
                swaps++;
                int curr_pos=t[v[i]];
                t[original[i]]=curr_pos;
                t[v[i]]=i;
                swap(original[curr_pos],original[i]);
            }
        }
        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        // lts use simple level order traversal and compute the number of swaps required to sort that leve
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            int index=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans+=swap_required(v);
        }
        return ans;
    }
};
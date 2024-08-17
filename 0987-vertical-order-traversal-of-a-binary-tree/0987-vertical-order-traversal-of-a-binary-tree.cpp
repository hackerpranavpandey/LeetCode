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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // the question can easily be solved using the concept of the top and bottom view
        // it give the indx wise correct but not in same level
        // so need to try a different approach
        // if(root==NULL)
        //     return {};
        // unordered_map<int,vector<int>> vertical_index;
        // queue<pair<TreeNode*,int>> t;
        // t.push({root,0});
        // int min_index=0,max_index=0;
        // while(!t.empty()){
        //     auto it=t.front();
        //     t.pop();
        //     TreeNode* temp=it.first;
        //     int index=it.second;
        //     vertical_index[index].push_back(temp->val);
        //     if(temp->left){
        //         t.push({temp->left,index-1});
        //         min_index=min(min_index,index-1);
        //     }
        //     if(temp->right){
        //         t.push({temp->right,index+1});
        //         max_index=max(max_index,index+1);
        //     }
        // }
        // int vertical_line=max_index-min_index+1;
        // vector<vector<int>> ans(vertical_line,vector<int>());
        // for(auto it:vertical_index){
        //     ans[it.first-min_index]=it.second;
        // }
        // return ans;
        queue<pair<TreeNode*,pair<int,int>>> t; // node,vertical,level
        unordered_map<int,map<int,multiset<int>>> mpp; // vertical,level,value set
        t.push({root,{0,0}});
        int min_vertical=0,max_vertical=0;
        // same concepts as top and bottom view
        while(!t.empty()){
            auto it=t.front();
            TreeNode* temp=it.first;
            t.pop();
            mpp[it.second.first][it.second.second].insert(temp->val);
            min_vertical=min(min_vertical,it.second.first);
            max_vertical=max(max_vertical,it.second.first);
            if(temp->left)
                 t.push({temp->left,{it.second.first-1,it.second.second+1}});
            if(temp->right)
                t.push({temp->right,{it.second.first+1,it.second.second+1}});
        }
        int range=max_vertical-min_vertical+1;
        vector<vector<int>> ans(range,vector<int>());
        for(auto it:mpp){
            vector<int> vertical;
            for(auto q:it.second){
                vertical.insert(vertical.end(),q.second.begin(),q.second.end());
            }
            if(vertical.size()!=0)
                ans[it.first-min_vertical]=vertical;
        }
        return ans;
    }
};
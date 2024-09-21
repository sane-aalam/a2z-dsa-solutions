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
    void rec(TreeNode* root, int target,int currentSum ,vector<int> ds,vector<vector<int>>& ans){
        if(root==NULL) return;
        currentSum +=root->val;
        ds.push_back(root->val);
        if(root->left==NULL && root->right==NULL && currentSum ==target){
            ans.push_back(ds);
            return;
        }

        rec(root->left,target,currentSum ,ds,ans);
        rec(root->right,target,currentSum ,ds,ans);

        // backtrack, reduce the sum, pop into the temp array 
        currentSum -=root->val;
        ds.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        if(root==NULL) return ans;
        rec(root,target,0,ds,ans);
        return ans;
    }
};
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
    void solve(TreeNode* root, int level, vector<int> & leftview){
         if(root == nullptr){
            return;
         }

         if(level == leftview.size()){
             leftview.push_back(root->val);
         }
         solve(root->left,level+1,leftview);
         solve(root->right,level+1,leftview);
    }
public:
    vector<int> leftSideView(TreeNode* root) {
         vector<int> leftview;
         int level = 0;
         solve(root,level,leftview);
         return leftview;
    }
};
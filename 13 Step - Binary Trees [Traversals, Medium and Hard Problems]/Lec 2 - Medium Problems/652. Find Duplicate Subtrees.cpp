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
      string solve(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &ans){
        // base case problem
        if(root == nullptr){
            return "";
        }

        // maintain duplicate into string ["24", "245"]
        // into into map [how many times]
        string str = to_string(root->val) + "," + solve(root->left,mp,ans) + "," + solve(root->right,mp,ans);
        // store the fquenecy into map
        mp[str]++;

        // Two trees are duplicate if they have the same structure with the same node values.
        // we have maintain the same structure into string 
        if(mp[str] == 2){
            ans.push_back(root);
        }
        return str;
      }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        // keep track the fequency of duplicate
        // "123" - 1 times
        // '123" - 2 times 
        // <string,int> 
        unordered_map<string, int> mp;
        
        // store the answer of root
        vector<TreeNode*> ans;
        solve(root, mp, ans);
        return ans;
    }
};
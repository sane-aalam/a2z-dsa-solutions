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
    void preorder(TreeNode* root,vector<int> & v1){
        
        if(root == nullptr) return;
        
        if(root->left == nullptr && root->right == nullptr){
            v1.push_back(root->val);
            return;
        }
        
        preorder(root->left,v1);
        preorder(root->right,v1);      
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1;
        vector<int> v2;
        
        preorder(root1,v1);
        preorder(root2,v2);

        // both are Equal return true
        if(v1 == v2){
            return true;
        }else{
            return false;
        }
    }
};
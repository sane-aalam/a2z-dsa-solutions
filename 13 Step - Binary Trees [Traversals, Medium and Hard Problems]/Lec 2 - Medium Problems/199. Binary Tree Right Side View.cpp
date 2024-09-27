// 199. Binary Tree Right Side View - BFS way

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
    // simple - level order traversal 
    // we can just need to store the last node of binary tree 
    // every level of nodes
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int index = 0; index < size; index++){
                TreeNode * currentNode = q.front();
                q.pop();

                if(currentNode->left != nullptr) q.push(currentNode->left);
                if(currentNode->right != nullptr) q.push(currentNode->right);

                // we want to only last Node of each level 
                if(index == size-1){
                    ans.push_back(currentNode->val);
                }
            }
        }
        return ans;
    }
};
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
    void solve(TreeNode * root, int currentSum, int targetSum, vector<int> temp, 
                 vector<vector<int>> & result){

        // base condition 
        // root is NULL return back!
         if(root == nullptr){
            return;
         }

        // sum me add kar rahe hay root->val
        // temp maintain kar rahe (all possible ways value we wants so track the current node value)
        currentSum = currentSum + root->val;
        temp.push_back(root->val);


// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
     // root to leaf node (base conditin hits)
         if(root->left == nullptr && root->right == nullptr){
             if(currentSum == targetSum){
                result.push_back(temp);
                return;
             }
         }
         solve(root->left,currentSum,targetSum,temp,result);
         solve(root->right,currentSum,targetSum,temp,result);
         
         // backTracking follow
         // reduce the root->val which you have taken, becuase this path done
         // we need to explore all paths 
         currentSum = currentSum - root->val;
         temp.pop_back();
         return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int currentSum = 0;
        vector<vector<int>> result;
        vector<int> temp;
        // root is nullptr then no need to calls DFS
        // return result[empty]
        if(root == nullptr){
            return result;
        }
        solve(root,currentSum,targetSum,temp,result);
        return result;
    }
};
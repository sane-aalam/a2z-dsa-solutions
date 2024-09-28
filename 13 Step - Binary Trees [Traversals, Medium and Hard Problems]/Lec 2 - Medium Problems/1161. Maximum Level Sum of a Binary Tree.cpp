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

The intution is simply to do bfs traversal of binary tree and at each level calculate the sum of nodes. If the curr level sum is greater than previous occuring levels we have the current level as answer. If the currsum and previous max sum are same we do nothing beacuse we have to return minimal level which was previously stored level only.

 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       
        int maximumSum = INT_MIN;
        int level = 0;

        // level order tarversal (simple)
        // think what you know alredy
        queue<TreeNode*> q;
        q.push(root);

        int resultLevel = 0;
        while(!q.empty()){
            int size = q.size();
            int currentSum = 0;
            for(int i = 0; i<size; i++){
                TreeNode * temp = q.front();
                q.pop();

                currentSum = currentSum + temp->val;

            // Both are not nullpter (left node, right node)
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }

            // incremenet level by 1 value
            // we have to keep track the level,because we want to return which level have maximum sum value 
            level = level + 1;

            if(currentSum > maximumSum){
                maximumSum = currentSum;
                resultLevel = level;
            }
        }
        return resultLevel;
    }
};
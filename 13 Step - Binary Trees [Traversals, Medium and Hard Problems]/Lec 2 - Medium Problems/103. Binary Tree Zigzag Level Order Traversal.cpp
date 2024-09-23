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

// Time complexity of this problem - 0(n)
// space complexity of this problem - 0(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         

        // create the 2D vector for storing the each level of binary tree 
        vector<vector<int>> finalResult;

        // root is nullptr Then return emptyresult
        if(root == nullptr){
            return finalResult;
        }
        // create the queue data stucture to perfom the bfs algorithm 
        queue<TreeNode*> q;
        q.push(root);
        int LeftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
    
    // creation of the levelcontianer for storing the each level
    // when one level completed, next level go change the direction to storing the into levelContianer 
    // simple = level order traversal Algorithm to solved 
            vector<int> levelContainer(size);
            for(int i = 0; i<size; i++){
                TreeNode * temp = q.front();
                q.pop();

            // put on the indexes all variable 
            // according to the left To right varaible 
            // the zigzag level order traversal of its nodes' values. 
            // from left to right, then right to left for the next level and alternate between).
                int index = LeftToRight? i : size-i-1;
                levelContainer[index] = temp->val;  
                
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }
        // need to change the direction variable
        // currently leftToRight variable is true
        // you have to make it false 
            LeftToRight = !LeftToRight;
            finalResult.push_back(levelContainer);
        }
        return finalResult;
    }
};









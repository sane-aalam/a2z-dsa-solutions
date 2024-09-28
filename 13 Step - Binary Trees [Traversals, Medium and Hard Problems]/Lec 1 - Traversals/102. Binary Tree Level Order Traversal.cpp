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
 *  */
//  create the 2-d array to maintain the result
// need to queue DSA to perform BFS algorithm (level-wise printing)
// Fifo [first in first out]
// When you popped the node, make sure left node is not null, or same for right not
// maintain the level of binary tree
// Tc and Sc - 0(N) number of nodes insert into queue
// queue.size(), queue.push(), queue.pop(), queue.empty()

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode *root){

        vector<vector<int>> levelOrderTraversal;

        // root is NULL,return empty result
        if (root == nullptr) {
            return levelOrderTraversal;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int currSizeQueue = q.size();
            // store each level one by one using [level array]
            // then after finishing one level, need to store into result-Array
            vector<int> level;
            while (currSizeQueue--)
            {
                TreeNode *temp = q.front();
                q.pop();

                // store the currentNode value
                level.push_back(temp->val);

                if (temp->left != nullptr){
                    q.push(temp->left);
                }

                if (temp->right != nullptr){
                    q.push(temp->right);
                }
            }
            levelOrderTraversal.push_back(level);
        }
        // Output: [[3],[9,20],[15,7]]
        return levelOrderTraversal;
    }
};

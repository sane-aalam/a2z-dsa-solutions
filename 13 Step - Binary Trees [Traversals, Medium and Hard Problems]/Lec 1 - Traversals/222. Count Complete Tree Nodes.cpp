/*

1. level order traversal:
2. store the array element
3. number of element = ( count complete trees nodes ) ==  array size 
            
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<int> v;
        if(root == nullptr){
            return 0;
        }

        // Design an algorithm that runs in less than O(n) time complexity.
        // Time complexity of algorithm - 0(n)
        // we are using extra space of 0(n) for queue 
        // number of nodes store into the queue 
        // level order traveral simple algorithm 
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        int size = v.size();
        return size;
    }
};
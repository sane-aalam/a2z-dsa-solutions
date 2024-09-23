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

// ans.first store diameter of binary Tree
// ans.second store height of the binary tree

pair<int,int> FastDiaMeter(TreeNode * root){

    // root is null
    if(root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> leftcall = FastDiaMeter(root->left);
    pair<int,int> rightcall = FastDiaMeter(root->right);    

    int option1 = leftcall.first;
    int option2 = rightcall.first;

    // height of the binary tree
    // left height of the binary tree + right height of the binary tree
    int option3 = leftcall.second + rightcall.second;

    pair<int,int> pairWiseResult;
    pairWiseResult.first = max(option1,max(option2,option3));
    pairWiseResult.second = max(leftcall.second,rightcall.second) + 1;

    return pairWiseResult;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return FastDiaMeter(root).first;
    }
};
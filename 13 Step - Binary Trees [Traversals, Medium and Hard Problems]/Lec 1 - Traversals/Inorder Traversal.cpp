/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing the inorder traversal of the tree.

// LNR - LEFT + NODE + RIGHT

void solve(Node* root, vector<int> & result){
     if(root == nullptr){
        return;
     }

     solve(root->left,result);
     result.push_back(root->data);
     solve(root->right,result);
}
vector <int> inorder(Node* root)
{
  // Your code here
   vector<int> result;
    solve(root,result);
    return result;
}
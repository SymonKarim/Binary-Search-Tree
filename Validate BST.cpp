#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int>&ans){
    if(!root) return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool solve(BinaryTreeNode<int> *root, int low,int high){
    if(!root) return true;
    
    if(root->data >=low and root->data<=high){
     bool left = solve(root->left, low, root->data);
     bool right = solve(root->right, root->data, high);
     return left && right;
    }else return false;

}
bool validateBST(BinaryTreeNode<int> *root) {
    //first approach using inorder traversal.
   /* vector<int>ans;
    inorder(root, ans);
    if(is_sorted(ans.begin(), ans.end())) return true;
    else return false;
    */
    // second approach using limit
    return solve(root, INT_MIN,INT_MAX);

}

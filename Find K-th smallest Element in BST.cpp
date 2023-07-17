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
int inOrder(BinaryTreeNode<int>* root, int &k){
    if(!root) return -1;

    int left = inOrder(root->left,k);
    if(left!=-1)return left;
    k--;
    if(k== 0) return root->data;
    return inOrder(root->right,k);
} 
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    // vector<int>ans;
    int ans = inOrder(root,k);
    return ans;
}

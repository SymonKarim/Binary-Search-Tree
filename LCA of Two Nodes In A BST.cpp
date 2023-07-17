#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBSTRecu(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(root == NULL) return NULL;

    if(root->data>P->data and root->data>Q->data){
        root = LCAinaBST(root->left,P,Q);
    }
     if(root->data<P->data and root->data<Q->data){
       root = LCAinaBST(root->right,P,Q);
    }
    return root;
}
TreeNode<int>* LCAinaBSTiterative(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	while(root){
          if (root->data > P->data and root->data > Q->data) {
           root = root->left;
          }else  if (root->data < P->data and root->data < Q->data) {
           root = root->right;
          } else return root;
    }
}

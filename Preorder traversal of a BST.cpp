#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int>*solve(int start, int end,vector<int>&preorder){
  if(start > end ) return NULL;

  int mid = (end+start)/2;
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[mid]);
  root->left = solve(start, mid-1,preorder);
  root->right = solve(mid+1,end,preorder);
  return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    sort(preorder.begin(), preorder.end());
    int n = preorder.size();
    return solve(0, n-1, preorder);
}

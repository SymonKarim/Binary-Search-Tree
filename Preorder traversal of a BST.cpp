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

// we can also solve this ques in O(N^2) 
// O(nlogn) space O(1);
BinaryTreeNode<int>*solve(int start, int end,vector<int>&preorder){
  if(start > end ) return NULL;

  int mid = (end+start)/2;
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[mid]);
  root->left = solve(start, mid-1,preorder);
  root->right = solve(mid+1,end,preorder);
  return root;
}
// Complexity O(N)
BinaryTreeNode<int>*solveOptimized(int min, int max,vector<int> &pre,int &i ){
   if(i>=pre.size()) return NULL;
   if(pre[i]<min or pre[i]>max) return NULL;
  
    BinaryTreeNode<int>* root =new BinaryTreeNode<int>(pre[i++]);
    root->left = solveOptimized(min, root->data, pre, i);
    root->right = solveOptimized(root->data, max, pre, i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // sort(preorder.begin(), preorder.end());
    // int n = preorder.size();
    // return solve(0, n-1, preorder);
    int min = INT_MIN, max = INT_MAX,i=0;
    return solveOptimized( min,max,preorder, i);
}

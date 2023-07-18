#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inOrderTraversal(TreeNode<int> *root, vector<int>&in){
   if(!root) return;
   inOrderTraversal(root->left, in);
   in.push_back(root->data);
   inOrderTraversal(root->right, in);
}
TreeNode<int> *inorderToBST(vector<int> &mergeVec, int start, int end){
    if(start>end )return NULL;

    int mid = (start + end)/2;
    TreeNode<int> * root = new TreeNode<int>(mergeVec[mid]);
    root->left = inorderToBST(mergeVec, start, mid-1);
    root->right = inorderToBST(mergeVec, mid+1,end);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1, in2, mergeVec;
    inOrderTraversal(root1, in1);
    inOrderTraversal(root2, in2);
    int i = 0 , j= 0;

  // O(N+M)
    while(i<in1.size() and j<in2.size()){
        if(in1[i]<=in2[j]){
          mergeVec.push_back(in1[i]);
          i++;
        }else{
          mergeVec.push_back(in2[j]);
          j++;
        }
    }
    while(i<in1.size()){
         mergeVec.push_back(in1[i]);
          i++;
    }
    while(j<in2.size()){
         mergeVec.push_back(in2[j]);
          j++;
    }
    int n = mergeVec.size()-1;
    return inorderToBST(mergeVec,0, n);
}

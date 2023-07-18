#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void solve(BinaryTreeNode<int>* root,vector<int>&ans){
    if(!root) return;
    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>ans;
    solve(root, ans);
    unordered_map<int,int>mp;
    for(auto i:ans){
        if(mp[target-i])return true;
        mp[i]++;
    }
    return false;
 }
//  using two pointer
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int>ans;
    solve(root, ans);
    int i = 0, j = ans.size()-1;
    while(i<j){
        int sum = ans[i]+ans[j];
        if(sum == target) return true;
        else if(sum>target) j--;
        else i++;
    }
    return false;
}

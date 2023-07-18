
void inOrder(TreeNode<int>* root,vector<int>&ans) {
    if(root == NULL) return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

TreeNode<int>* solve(int start, int end,vector<int>&ans){
  if(start > end ) return NULL;

  int mid = (end+start)/2;
  TreeNode<int>* root = new TreeNode<int>(ans[mid]);
  root->left = solve(start, mid-1,ans);
  root->right = solve(mid+1,end,ans);
  return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int>ans;
    inOrder(root, ans);
    int n = ans.size();
    return solve(0, n-1, ans);
}

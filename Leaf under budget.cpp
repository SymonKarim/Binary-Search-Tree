class Solution
{
public:
    void check(Node* root, int store, vector<int>&mp){
         if(root==NULL)return;
        if(root->left== NULL and root->right==NULL) {
            mp.push_back(store);
        }
       check(root->left,store+1, mp);
       check(root->right, store+1, mp); 
     
    }
    int getCount(Node *root, int k)
    {
        //code here
        if(!root) return 0;
        int cnt = 0;
       vector<int>mp;
       check(root, 1,mp);
        sort(mp.begin(), mp.end());
        int sum =0;
        for(auto i:mp){
         sum +=i;
         if(sum>k) break;
         cnt++;
        }
        return cnt;
    }
};

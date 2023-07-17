class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node *temp1 = root, *temp2 = root;
        while(temp1){
           
                if(temp1->key > key){
                    suc = temp1;
                    temp1 = temp1->left;
                }else temp1 = temp1->right;
            }
        
          while(temp2){
                if(temp2->key < key){
                    pre = temp2;
                    temp2 = temp2->right;
                }else temp2 = temp2->left;
            }
        }
    
};

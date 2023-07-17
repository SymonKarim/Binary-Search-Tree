//*Bismillahir Rahmanir Raheem
//! symonkarim
#include <bits/stdc++.h>
#define FASTER ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
//!------

#define ll long long

class node {
public:
    int val;
    node* left;
    node* right;

    node(int data) {
        this->val = data;
        this->left = NULL;
        this ->right = NULL;
    }
};
node* insertinBST(node* root, int data) {
    if (root == NULL) {
        root = new node(data);
        return root;
    }
    if (data > root->val) {
        root->right = insertinBST(root->right, data);
    } else {
        root->left = insertinBST(root->left, data);;
    }
    return root;
}
void buildTree(node* &root) {
    int data; cin >> data;
    while (data != -1) {
        cout << data << ' ';
        root = insertinBST(root, data);
        cin >> data;
    }
}
void traverseTree(node* root) {
    queue<node*>q;
    q.push(root);
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        cout << "level " << level++ << "-> ";

        for (int i = 1; i <= size; i++) {
            node* temp  = q.front();
            q.pop();
            if (temp) cout << temp->val << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}
node* inOrderTraverse(node* root) {
    if (root == NULL) return NULL;
    root->left = inOrderTraverse(root->left);
    cout << root->val << ' ';
    root->right = inOrderTraverse(root->right);

    return root;

}
node* preOrderTraverse(node* root) {
    if (root == NULL) return NULL;
    cout << root->val << ' ';
    root->left = preOrderTraverse(root->left);
    root->right = preOrderTraverse(root->right);

    return root;

}
node* postOrderTraverse(node* root) {
    if (root == NULL) return NULL;

    root->left = postOrderTraverse(root->left);
    root->right = postOrderTraverse(root->right);
    cout << root->val << ' ';
    return root;

}

void leverOrderTraversal(node* &root) {

    queue<node*>q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) {
            q.push(temp->left);
        } if (temp->right) {
            q.push(temp->right);
        }

    }
}
bool search(node* root, int target) {
    while (root != NULL) {
        if (root->val == target) {
            return true;
        }
        else if (root->val > target) {
            root = root->left;
        } else root = root->right;
    }
    return false;
}
int getMax(node* root) {
    int ans = 0;
    while (root != NULL) {
        ans = root->val;
        root = root->right;
    }
    return ans;
}
node* getMin(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
void findPreSucc(node *root , int key, node*& pre, node*& suc) {
    node* temp1 = root;
    while (temp1) {
        // the maximum value in left subtree is successor
        if (temp1->val > key) {
            suc = temp1;
            temp1 = temp1->left;
        }
        else
            temp1 = temp1->right;
    }
    node* temp2 = root;
    while (temp2) {
        // the minimum value in right subtree is predecessor
        if (temp2->val < key) {
            pre = temp2;
            temp2 = temp2->right;
        }
        else
            temp2 = temp2->left;
    }
    return;
}
node* deleteFromBST(node* root, int key) {
    if (!root) return NULL;

    if (root->val == key) {
        //0 children
        if (root->left == NULL and root->right == NULL) {
            delete root;
            return NULL;
        }


        //1children
        // for left child cases
        if (root->left != NULL and root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        } if (root->left == NULL and root->right != NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }


        //2children
        if (root->left != NULL and root->right != NULL) {
            int min = getMin(root->right)->val;
            root->val = min;
            return deleteFromBST(root->right, min);
        }



    } else if (root->val > key) {
        root->left = deleteFromBST(root->left, key);
    } else {
        root->right = deleteFromBST(root->right, key);
    }
}
int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    node* root = NULL;
    buildTree(root);
    cout << endl;
    cout << "inOrderTraverse: ";
    inOrderTraverse(root);
    cout << endl;
    cout << "preOrderTraverse: ";
    preOrderTraverse(root);
    cout << endl;
    cout << "postOrderTraverse: ";
    postOrderTraverse(root);
    cout << endl;
    cout << "leverOrderTraversal: " << endl;
    traverseTree(root);
    cout << endl;
    deleteFromBST(root, 8);
    cout << "After deleting 8" << endl;
    traverseTree(root);
    cout<<endl;
    // leverOrderTraversal(root);
    cout << (search(root, 3) == 1 ? "Available" : "NotAvailable") << endl;
    cout << "Max: " << getMax(root) << endl;
    cout << "Min: " << getMin(root)->val << endl;
    cout << "finding predicessor and successor of 5" << endl;
    node *pre = NULL, *suc = NULL;
    findPreSucc(root, 5, pre, suc);
    if (pre != NULL)
        cout << "Predecessor is " << pre->val << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is " << suc->val;
    else
        cout << "No Successor";

    return 0;
}
/*
input: 10 8 21 7 27 5 4 3 -1

output:
10 8 21 7 27 5 4 3 
inOrderTraverse: 3 4 5 7 8 10 21 27 
preOrderTraverse: 10 8 7 5 4 3 21 27 
postOrderTraverse: 3 4 5 7 8 27 21 10 
leverOrderTraversal: 
level 1-> 10 
level 2-> 8 21 
level 3-> 7 27 
level 4-> 5 
level 5-> 4 
level 6-> 3 

After deleting 8
level 1-> 10 
level 2-> 7 21 
level 3-> 5 27 
level 4-> 4 
level 5-> 3 
Available
Max: 27
Min: 3
finding predicessor and successor of 5
Predecessor is 4
Successor is 7
*/

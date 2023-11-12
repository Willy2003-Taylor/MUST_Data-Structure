#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node* insert_node(node* root, int val){
    if(root == nullptr)
        return new node(val);
    
    if(val < root->data)
        root->left = insert_node(root->left, val);
    else root->right = insert_node(root->right, val);

    return root;
}   

node* min_node(node* root){
    node* current = root;
    while(current && current->left != nullptr)
        current = current->left;
    return current;
}

node* delete_node(node* root, int val){
    if(root == nullptr)
        return nullptr;

    if(val < root->data)
        root->left = delete_node(root->left, val);
    else if(val > root->data)
        root->right = delete_node(root->right, val);
    
    /*Delete the root*/
    else{
        /*Case 1: the root has no children or only one child*/

        if(root->left == nullptr){
            node* tmp = root->right;
            delete root;
            root = nullptr;
            return tmp;
        }

        else if(root->right == nullptr){
            node* tmp = root->left;
            delete root;
            root = nullptr;
            return tmp;
        }

        /*Case 2: the root has two children*/

        /*2 ways to delete the root to maintain the property
        of BST simultaneously
        
        (1) Find the minima of the right subtree
        (2) Find the maxima of the left subtree*/

        /*We choose the first one to finish the implementation*/

        node* minnode = min_node(root->right);
        root->data = minnode->data;
        root->right = delete_node(root->right, minnode->data);
    }
    return root;    
}

void inorder_traversal(node* root){
    if(root != nullptr){
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
}

int main(){
    node* root = nullptr;

    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    inorder_traversal(root);
    cout<<endl;

    root = delete_node(root, 20);
    root = delete_node(root, 30);
    root = delete_node(root, 70);

    inorder_traversal(root);
    cout<<endl;

    return 0;
}
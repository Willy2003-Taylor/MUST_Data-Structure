#include<bits/stdc++.h>
using namespace std;
struct node{
    node* left;
    node* right;
    int data;
    node(int x): data(x), left(nullptr), right(nullptr) {}
};

void insert(node* &root, int value){
    if(root == nullptr){
        root = new node(value);
        return;
    }

    if(value < root->data)
        insert(root->left, value);
    else insert(root->right, value);

}

void preorder_traversal(node* root){
    deque<node*> dq;
    node* current = root;
    while(current != nullptr || !dq.empty()){
        while(current != nullptr){
            cout<<current->data<<" ";
            dq.push_back(current);
            current = current->left;
        }

        if(!dq.empty()){
            current = dq.back();
            dq.pop_back();
            current = current->right;
        }
    }
    cout<<endl;
}

void inorder_traversal(node* root){
    deque<node*> dq;
    node* current = root;
    while(current != nullptr || !dq.empty()){
        while(current != nullptr){
            dq.push_back(current);
            current = current->left;
        }

        if(!dq.empty()){
            current = dq.back();
            cout<<current->data<<" ";
            dq.pop_back();
            current = current->right;
        }
    }
    cout<<endl;
}

void postorder_traversal(node* root){
    deque<node*> dq1;
    deque<int> dq2;
    node* current = root;
    while(current != nullptr || !dq1.empty()){
        while(current != nullptr){
            dq2.push_back(current->data);
            dq1.push_back(current);
            current = current->right;
        }

        if(!dq1.empty()){
            current = dq1.back();
            dq1.pop_back();
            current = current->left;
        }
    }

    while(!dq2.empty()){
        cout<<dq2.back()<<" ";
        dq2.pop_back();
    }
    cout<<endl;
}

int main(){
    node* root = new node(0);
    insert(root, 42);
    insert(root, 35);
    insert(root, 50);
    insert(root, 25);
    insert(root, 40);
    insert(root, 43);
    insert(root, 79);
    preorder_traversal(root);
    inorder_traversal(root);
    postorder_traversal(root);
    return 0;
}
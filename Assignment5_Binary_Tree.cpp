#include<bits/stdc++.h>
using namespace std;
const int max_size = 100;
int tree[max_size];
/*Implement the traversal when the tree is defined as 1-dimension array,
using recursion algorithm first*/


/*Do the same thing when the tree is defined using pointer,
using non-recursion then*/

struct node{
    int data;
    node* left, *right;
};

node* createnode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

void pre_order_traversal_arr(int a[], int index){
    if((a[index] && index > 1) || (a[index] == 0 && index == 1)){
        cout<<a[index]<<" ";
        pre_order_traversal_arr(a, 2*index);
        pre_order_traversal_arr(a, 2*index + 1);
    }
}
/*when the tree is defined as array, the sign of empty must be 0
since the position where there is no data is defined as 0 by default
*/

void in_order_traversal_arr(int a[], int index){
    if((a[index] && index > 1) || (a[index] == 0 && index == 1)){
        in_order_traversal_arr(a, 2*index);
        cout<<a[index]<<" ";
        in_order_traversal_arr(a, 2*index + 1);
    }
}

void post_order_traversal_arr(int a[], int index){
    if((a[index] && index > 1) || (a[index] == 0 && index == 1)){
        post_order_traversal_arr(a, 2*index);
        post_order_traversal_arr(a, 2*index + 1);
        cout<<a[index]<<" ";
    }
}

void pre_order_traversal_pt(node* root){
    if(!root) return;
    node* stack[max_size];
    int top = -1;
    stack[++top] = root;
    while(top >= 0){
        node* current = stack[top--];
        cout<<current->data<<" ";
        if(current->right)
            stack[++top] = current->right;
        if(current->left)
            stack[++top] = current->left;
    }
}

void in_order_traversal_pt(node* root){
    if(!root) return;
    node* stack[max_size];
    int top = -1;
    node* current = root;
    while(current || top >= 0){
        while(current){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        cout<<current->data<<" ";
        current = current->right;
    }
}

void post_order_traversal_pt(node* root){
    node* s1[max_size];
    node* s2[max_size];
    int top1 = -1, top2 = -1;
    s1[++top1] = root;
    while(top1 >= 0){
        node* current = s1[top1--];
        s2[++top2] = current;
        if(current->left)
            s1[++top1] = current->left;
        if(current->right)
            s1[++top1] = current->right;
    }
    while(top2 >= 0){
        node* current = s2[top2--];
        cout<<current->data<<" ";
    }
}

int main(){
    int n;
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(4);
    root->left->right = createnode(5);
    pre_order_traversal_pt(root);
    cout<<endl;
    in_order_traversal_pt(root);
    cout<<endl;
    post_order_traversal_pt(root);
    return 0;
}
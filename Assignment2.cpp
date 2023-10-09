#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};


node* create_node(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = nullptr;
    return newnode;
}

node* dummyHead = create_node(0);

void list_insert(node** head, int index, int val){
    dummyHead->next = *head;
    node* current = dummyHead;
    node* newnode = create_node(val);

    if(index == 0){
        current->next = newnode;
        *head = newnode;
        return;
    }
    //add head node

    while(index--)
        current = current->next;
    newnode->next = current->next;
    current->next = newnode;
}

void list_delete(node** head, int index){
    int k = index - 1;
    dummyHead->next = *head;
    node* current = dummyHead->next;
    if(index == 0){
        node* tmp = current;
        *head = current->next;
        free(tmp);
        tmp = nullptr;
        return;
    }
    //delete head node
    while(k--)
        current = current->next;
    node* tmp = current->next;
    current->next = current->next->next;
    free(tmp);
    tmp = nullptr;
}

void search(node* head, int index){
    if(head == nullptr){
        printf("List is empty.\n");
        return;
    }
    if(index < 0){
        printf("Invalid index.\n");
        return;
    }

    node* current = head;
    while(index--)
        current = current->next;
    printf("%d", current->data);
}

void list_sort(node* head){
    node* p1 = head;
    node* p2;
    while(p1 != nullptr){
        p2 = p1->next;
        while(p2 != nullptr){
            if(p1->data > p2->data)
                swap(p1->data, p2->data);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

node* sort_merge(node* head1, node* head2){
    if(head1 == nullptr)
        return head2;
    if(head2 == nullptr)
        return head1;
    node* current = head1;
    if(current != nullptr)
        current = current->next;
    current->next = head2;
    list_sort(head1);
    return head1;
}

void print(node* head){
    dummyHead->next = head;
    node* current = dummyHead;
    while(current->next != nullptr){
        printf("%d ", current->next->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct node* head1 = nullptr;
    struct node* head2 = nullptr;
    struct node* merged;
    list_insert(&head1, 0, 1);
    list_insert(&head1, 1, 2);
    list_insert(&head2, 0, 3);
    list_insert(&head2, 1, 4);
    merged = sort_merge(head1, head2);
    print(merged);
    return 0;
}
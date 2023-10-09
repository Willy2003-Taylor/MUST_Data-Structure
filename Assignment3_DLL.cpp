//basic operations for doubly-linked list

#include<bits/stdc++.h>
using namespace std;
int cnt;
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList{
    struct Node* head;
};

void init(DoublyLinkedList* list){
    list->head = nullptr;
}

void insert_node_beginning(DoublyLinkedList* list, int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->prev = nullptr;
    newnode->next = list->head;
    //initialize
    if(list->head != nullptr){
        list->head->prev = newnode;
        cnt++;
    }
    //if the head of the list is not null
    list->head = newnode;
    /*Consider the initial condition that there are no nodes
    we need to insert an initial node, which is equivalent to insert at the beginning.*/
    cnt++;
}

void insert_node_end(DoublyLinkedList* list, int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = nullptr;
    //initialize
    if(list->head == nullptr){
        newnode->prev = nullptr;
        list->head = newnode;
        cnt++;
        return;
    }
    /*Consider the head of the list is null
    the node inserted to the end of the list is equivalent
    to the head node of the list
    */
    Node* current = list->head;
    while(current->next != nullptr)
        current = current->next;
    current->next = newnode;
    newnode->prev = current;
    cnt++;
}

void insert_node_index(DoublyLinkedList* list, int data, int index){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->prev = nullptr;
    newnode->next = nullptr;
    //initialize
    if(list->head == nullptr){
        list->head = newnode;
        return;
    }
    //if the head of the list is null, insert the node at the beginning
    if(index == 0){
        newnode->next = list->head;
        list->head->prev = newnode;
        list->head = newnode;
        //update to make the newnode become the current head node of the list
        return;
    }

    Node* current = list->head;
    while(index--)
        current = current->next;
    newnode->next = current->next;
    newnode->prev = current;
    if(current->next != nullptr)
        current->next->prev = newnode;
    current->next = newnode;
    cnt++;
    //insert a node after the given index
}   

void delete_node(DoublyLinkedList* list, int data){
    Node* current = list->head;
    while(current != nullptr){
        if(current->data == data){
            if(current->prev != nullptr)
                current->prev->next = current->next;
            else list->head = current->next;
            //if the previous pointer is null, which means the current pointer is head of the list
            //after deletion, the next of the current should be the head node
            if(current->next != nullptr)
                current->next->prev = current->prev;
            free(current);    
        }
        current = current->next;
        cnt--;
    }
}

void search(DoublyLinkedList* list, int index){
    if(list->head == nullptr){
        printf("Search failed.");
        return;
    }
    if(index < 0 || index > (cnt - 1)){
        printf("Invalid search.");
        return;
    }

    Node* current = list->head;
    while(index--)
        current = current->next;
    printf("%d", current->data);
}

void print(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current= current->next;
    }
    cout<<endl;
}

void list_sort(Node* head){
    Node* p1 = head;
    Node* p2;
    while(p1 != nullptr){
        p2 = p1->next;
        while(p2 != nullptr){
            if(p1->data >= p2->data)
                swap(p1->data, p2->data);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

Node* merge_list(Node* head1, Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;
    //if one of the lists is empty, return the other one
    Node* current = head1;
    while(current->next != nullptr)
        current = current->next;
    current->next = head2;
    head2->prev = current;
    list_sort(head1);
    return head1;
}

int main(){
    struct DoublyLinkedList list1;
    struct DoublyLinkedList list2;
    struct Node* merged;
    init(&list1);
    init(&list2);
    
    insert_node_end(&list1, 2);
    insert_node_end(&list1, 8);
    insert_node_end(&list1, 5);
    insert_node_end(&list2, 7);
    merged = merge_list(list1.head, list2.head);
    print(merged);
    return 0;
}
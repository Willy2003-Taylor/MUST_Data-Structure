//basic operations for single circular linked list

#include<bits/stdc++.h>
using namespace std;
int cnt;
struct node{
    int data;
    node* next;
};

//create a node for the linked list
node* create_node(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = nullptr;
    return newnode;
}

void insert_node_beginning(node** head, int data){
    node* newnode = create_node(data);
    if(*head == nullptr){
        *head = newnode;
        newnode->next = newnode;
        cnt++;
        /*let the newnode be the head node
        and the next pointer points to newnode itself*/
        return;
    }
    else{
        /*under the condition that the head node is not null,
        we are not allowed to directly insert the node before the head node.
        since this is a circular linked list, 
        the last node's pointer points to the head node.*/
        node* last = *head;
        while(last->next != *head)
            last = last->next;
        last->next = newnode;
        newnode->next = *head;
        *head = newnode;
        cnt++;
        return;
    }
}

void insert_node_end(node** head, int data){
    node* newnode = create_node(data);
    if(*head == nullptr){
        *head = newnode;
        newnode->next = newnode;
        cnt++;
        return;
        /*why should consider this situation?
        when inserting node to the end, specifically
        when the head node is null, the node inserted
        just becomes the head node*/
    }
    else{
        node* last = *head;
        while(last->next != *head)
            last = last->next;
        last->next = newnode;
        newnode->next = *head;
        cnt++;
        return;
    }
}

void insert_node_index(node** head, int data, int index){
    if(index < 0){
        printf("Invalid index, insertion fails.");
        return;
    }
    if(index == 0){
        insert_node_beginning(head, data);
        return;
    }

    node* newnode = create_node(data);
    node* current = *head;
    while(index--)
        current = current->next;
    newnode->next = current->next;
    current->next = newnode;
    cnt++;
}

void delete_node_beginning(node** head){
    if(*head == nullptr){
        printf("The list is empty. Deletion is failed.");
        return;
    }
    if((*head)->next == (*head)){
        delete(*head);
        *head = nullptr;
        cnt--;
        return;
    }
    /*consider the list only has a head node*/

    node* tmp = *head;
    node* Todelete = *head;
    //the node will be deleted
    while(tmp->next != *head)
        tmp = tmp->next;
    tmp->next = (*head)->next;
    *head = (*head)->next;
    free(Todelete);
    Todelete = nullptr;
    cnt--;
}

void delete_node_end(node** head){
    if(*head == nullptr){
        printf("The list is empty. Deletion is failed.");
        return;
    }
    if((*head)->next == nullptr){
        delete(*head);
        *head = nullptr;
        cnt--;
        return;
    }

    node* last = *head;
    node* Todelete, *prev;
    while(last->next != *head){
        prev = last;
        last = last->next;
    }
    Todelete = last;
    prev->next = *head;
    free(Todelete);
    Todelete = nullptr;
    cnt--;
}

void delete_node_index(node** head, int index){
    if(*head == nullptr){
        printf("The list is empty. Deletion failed.");
        return;
    }
    
    if(index < 0){
        printf("Invalid deletion.");
        return;
    }
    if(index == 0){
        delete_node_beginning(head);
        return;
    }

    node* current = *head;
    node* Todelete;
    int k = index - 1;
    while(k--)
        current = current->next;
    Todelete = current->next;
    current->next = Todelete->next;
    free(Todelete);
    Todelete = nullptr;
    cnt--;
}

void search(node* head, int index){
    if(head == nullptr){
        printf("Search failed.");
        return;
    }
    if(index < 0 || index > (cnt - 1)){
        printf("Invalid search.");
        return;
    }

    node* current = head;
    while(index--)
        current = current->next;
    printf("%d", current->data);
}

node* list_merge(node* head1, node* head2){
    if(head1 == nullptr)
        return head2;
    if(head2 == nullptr)
        return head1;
    
    node* current = head1;
    while(current->next != head1)
        current = current->next;
    current->next = head2;
    current = head2;

    while(current->next != head2)
        current = current->next;
    current->next = head1;
    return head1;
}


void print(node* head){
    if(head == nullptr){
        printf("The list is empty.");
        return;
    }
    node* current = head;
    do{
        cout<<current->data<<" ";
        current = current->next;
    }while(current != head);
    cout<<endl;
    /*please notice that we can't judge the "current" pointer first
    because it may lead to print nothing
    we need to print the head node first and judge then*/
}

int main(){
    struct node* head1 = nullptr;
    struct node* head2 = nullptr;
    insert_node_end(&head1, 5);
    insert_node_end(&head1, 3);
    insert_node_index(&head1, 2, 1);
    insert_node_end(&head2, 3);
    insert_node_end(&head2, 5);
    print(head1);
    list_merge(head1, head2);
    print(head1);
    return 0;
}
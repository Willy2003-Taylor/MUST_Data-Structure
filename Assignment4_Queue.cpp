/*some operations for circular queue
Firstly, define the circular queue in static form, 
which is represented by 1-dimensional array
Then, define it as linked list*/
#include<bits/stdc++.h>
using namespace std;
const int max_size = 10;

struct node{
    int data;
    node* next;
};

struct queue_circular_node{
    node* front, *rear;
};

struct queue_circular_arr{
    int front, rear;
    int q[max_size];
};

void init_arr(queue_circular_arr* cq){
    cq->front = 0;
    cq->rear = 0;
}

void init_node(queue_circular_node* cq){
    node* head;
    head = (node*)malloc(sizeof(node));
    head->next = nullptr;
    cq = (queue_circular_node*)malloc(sizeof(queue_circular_node));
    cq->front = cq->rear = head;
}
/*two pointers are needed, one for the linked list
the other for the whole queue*/

void insert_arr(queue_circular_arr* cq, int data){
    if((cq->rear + 1) % max_size == cq->front){
        printf("Insertion failure.");
        return;
    }
    cq->q[cq->rear] = data;
    cq->rear = (cq->rear + 1) % max_size;
}

void insert_node(queue_circular_node* cq, int data){
    node* current = (node*)malloc(sizeof(node));
    if(!current){
        printf("Insertion failure.");
        return;
    }
    current->data = data;
    current->next = nullptr;

    if(cq->front == nullptr){
        cq->front = current;
        cq->rear = current;
    }
    else{
        cq->rear->next = current;
        cq->rear = current;
    }
}

int delete_arr(queue_circular_arr* cq){
    int x;
    if(cq->front == cq->rear){
        printf("The queue is empty.");
        return -1;
    }

    x = cq->q[cq->front];
    cq->front = (cq->front + 1) % max_size;
    return x;
}

int delete_node(queue_circular_node* cq){
    int x;
    node* current;
    if(cq->front == cq->rear){
        printf("Empty queue.");
        return -1;
    }
    current = cq->front->next;
    x = current->data;
    cq->front->next = current->next;
    if(current == cq->rear)
        cq->front = cq->rear;
    free(current);
    current = nullptr;
    return x;
}

int main(){
    struct queue_circular_arr queue1;
    struct queue_circular_node queue2;
    init_arr(&queue1);
    init_node(&queue2);
    insert_arr(&queue1, 10);
    insert_arr(&queue1, 20);
    insert_arr(&queue1, 30);
    insert_arr(&queue1, 40);

    printf("%d ", delete_arr(&queue1));
    printf("%d ", delete_arr(&queue1));
    printf("%d ", delete_arr(&queue1));
    printf("%d ", delete_arr(&queue1));

    insert_node(&queue2, 10);
    insert_node(&queue2, 20);
    insert_node(&queue2, 30);
    insert_node(&queue2, 40);

    printf("%d ", delete_node(&queue2));
    printf("%d ", delete_node(&queue2));
    printf("%d ", delete_node(&queue2));
    printf("%d ", delete_node(&queue2));
    return 0;
}
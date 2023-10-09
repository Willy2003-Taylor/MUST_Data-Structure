#include<iostream>
using namespace std;
int n,x;
struct Queue{
    int *queue;
    int head,tail;
    int size;
    int length;
};

void queue_init(struct Queue *q){
    q->size=n;
    q->head=0;
    q->tail=0;
    q->queue=(int*)malloc(sizeof(int)*q->size);
    q->length=0;
}

void enqueue(struct Queue *q, int x){
    if(q->length==q->size)
        printf("The queue overflows.");
    else{
        q->queue[q->tail]=x;
        q->tail++;
        q->length++;
        if(q->tail==q->size)
            printf("The queue overflows.");
    }
    printf("after enqueue: ");
    for(int i=0;i<q->length;i++)
        printf("%d ",q->queue[i]);
}

void dequeue(struct Queue *q1, struct Queue *q2){
    int x;
    if(q1->length==0)
        printf("The queue underflows.");
    else{
        for(int i=0;i<=q1->length-1;i++){
            x=q1->queue[i];
            q2->queue[q2->tail]=x;
            q1->head++;
            q1->length--;
            q2->tail++;
            q2->length++;
        }
        x=q1->queue[q1->head];
        printf("after dequeue: ");
        printf("%d ",x);
        for(int i=q2->length-1;i>=0;i--)
            printf("%d ",q2->queue[i]);
    }
}

int main(){
    struct Queue q1;
    struct Queue q2;
    scanf("%d",&n);
    queue_init(&q1);
    queue_init(&q2);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(&q1,x);
    }
    printf("\n");
    dequeue(&q1, &q2);
    return 0;
}
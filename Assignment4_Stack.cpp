/*Define the stack as a 1-dimensional array, 
which is static and cannot be modified, 
and a linked list, which is dynamic.*/
#include<bits/stdc++.h>
using namespace std;
const int max_size = 100;
struct Stack_arr{
    int top;
    int s[max_size];
};

struct Stack_node{
    int data;
    Stack_node* next;
};

void init_arr(Stack_arr* stack){
    stack->top = 0;    
}

void init_node(Stack_node* stack){
    Stack_node* top = (Stack_node*)malloc(sizeof(Stack_node));
    top->next = nullptr;
}

void push_arr(Stack_arr* stack, int data){
    if(stack->top == max_size - 1){
        printf("Overflow.");
        return;
    }

    stack->top++;
    stack->s[stack->top] = data;
}

void push_node(Stack_node* top, int data){
    Stack_node* current = (Stack_node*)malloc(sizeof(Stack_node));
    if(!current){
        printf("Empty stack!");
        return;
    }
    current->data = data;
    current->next = top->next;
    top->next = current;
}

int pop_arr(Stack_arr* stack){
    if(stack->top == -1){
        printf("Underflow");
        return -1;
    }
    int data = stack->s[stack->top];
    stack->top--;
    return data;
}

int pop_node(Stack_node* top){
    Stack_node* current;
    if(!top->next){
        printf("Empty stack!");
        return -1;
    }
    current = top->next;
    int data = current->data;
    top->next = current->next;
    free(current);
    current = nullptr;
    return data;    
}

int main(){
    struct Stack_arr stack1;
    struct Stack_node stack2;
    init_arr(&stack1);
    push_arr(&stack1, 10);
    push_arr(&stack1, 20);
    push_arr(&stack1, 30);
    push_arr(&stack1, 40);
    printf("%d\n", pop_arr(&stack1));
    printf("%d\n", pop_arr(&stack1));

    push_node(&stack2, 10);
    push_node(&stack2, 20);
    push_node(&stack2, 30);
    printf("%d\n", pop_node(&stack2));
    printf("%d\n", pop_node(&stack2));
    return 0;
}
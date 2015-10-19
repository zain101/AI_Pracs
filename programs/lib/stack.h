
typedef struct SNode{
    int data;
    struct SNode *next;
}snode;

typedef struct Stack{
    struct SNode *top;
}stack;

snode *HEAD  = NULL;
void push(int d, stack *s);
int pop(stack *s);
int is_empty(stack *s);
void initialize_s(stack *s);
/*
int main(){
    stack s;
    int a;
    initialize_s(&s);
    push(10, &s);
    push(20, &s);
    push(30, &s);
    a = s.top->data;
    printf("\n %d", a);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    return 0;
}
*/
void initialize_s(stack *s){
    s->top = NULL;
}

void push(int d, stack *s){
    snode *n = (snode *)malloc(sizeof(snode));
    n->data = d;
    n->next = NULL;
    if(s->top == NULL){
        s->top = n;
        }
    else{
        n->next = s->top;
        s->top = n;
    }
    //printf("\nPushed %d\n", d);
}


int  pop(stack *s){
    int data;
    if(s->top != NULL){
        snode *n;
        stack *tmp;
        n = s->top;
        s->top = n->next;
        data = n->data;
        //printf("\nPoped item %d",n->data );
        free(n);
        return data;
    }
    else{
        printf("\nStack is empty");
    }

}

int is_S_empty(stack *s){
  if(s->top  == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

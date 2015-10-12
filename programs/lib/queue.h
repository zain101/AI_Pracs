
//This is the struct for pointing front and rear in a queue.
struct Q{
  struct QNode *rear ;
  struct QNode *front ;

};

//This struct creates the node for the queue which is then pointed by the front and rear.
struct QNode{
    struct QNode *next;
    int data;
};

//This initialize the front and rear to NULL
void initializeQ(struct Q *tmp){
  tmp->rear = NULL;
  tmp->front = NULL;
}

//If either of front and rear is NULL t hen Queue is empty
int isQempty(struct Q *tmp){
  if(tmp->rear  == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

void displayQ(struct Q *tmp){
  struct QNode *p = tmp->front;
  printf("\nElements of Queue are: \n");
  while(p != NULL){
    printf("\t%d", p->data);
    p = p->next;
  }
  printf("\n" );
}

/*
* This creates a new node.
* Attact this node to the Queue if its already avalible, if not make this as first node.
* front points to the first node
* rear points to the newly inserted node.
*/
void enqueue(struct Q *q, int data){
  struct QNode *n;
  n = (struct QNode *)malloc(sizeof(struct QNode));
  n->next = NULL;
  n->data = data;
  if(isQempty(q)){
    q->rear = n;
    q->front = n;
  }
  else{
    (q->rear)->next = n;
    q->rear = n;
  }

}

/*
  This method delete the node from the Queue, from front-end
  front pointer is moved ahead in Queue.
  If this is the last node the Front=Rear=NULL
  the node is freed from the memory.
*/
int dequeue(struct Q *tmp){
  int data;
  struct QNode *p;
  if(isQempty(tmp)){
    printf("\nQueue is Empty" );
    return -1;
  }
  else{
    p = tmp->front;
    data = p->data;
    if(tmp->rear == tmp->front)
      initializeQ(tmp);
    else
      tmp->front = p->next;
  }
  free(p);
  return data;
}

/*
 //Uncomment this section to run this code independentely, for testing purpose.

int main(){
  struct Q q;
  int i, j;
  initializeQ(&q);
  printf("\nEnter 3 elements: ");
  for(i=0; i<3; i++){
    scanf("%d",&j);
    enqueue(&q, j);
  }
  printf("\nDisplaying queue");
  displayQ(&q);
  j = dequeue(&q);
  printf("\nDisplaying queue after deletion\n");
  displayQ(&q);

  return 0;
}
*/

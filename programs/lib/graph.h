
typedef struct Node{
  int d;
  struct Node *next;
  int vertex;

}node;

node *G[MAX];
void readGraph();
void insert_Graph(int a, int b, int c);
void displayGraph();


void readGraph(){
    int i, j, e, a, b, c;
    printf("\nEnter the number of vertex in graph: " );
    scanf("%d",&v);
    printf("\nEnter the number of Edges: " );
    scanf("%d",&e);
    for(i=0; i<v; i++)
        G[i] = NULL;

    for ( i = 0; i < e; i++) {
      printf("\nGive the edges between(U, V) in this format(1 2) and its cost: " );
      scanf("%d  %d %d",&a, &b, &c);
      insert_Graph(a, b, c);
    }

}

void insert_Graph(int a, int b, int c){
  node *p, *q;
  /*Acquire the memory for the new node and 'p' points to that memory*/
  p  = (node *)malloc(sizeof(node));
  p->next=NULL;
  p->vertex=b;
  p->d = c;
  /*Insert the node in the linked list of the graph*/
  if(G[a] == NULL)
    G[a]=p;
  else{
      /*goto the end of list and insert the edge*/
      q = G[a];
      while(q->next != NULL){
        q = q->next;
      }
      q->next = p;
  }
}


void displayGraph(){
  int i=0;
  node *q;
  for(i=0; i<v; i++){
    q = G[i];
    printf("\nVertex %d is connected to these many vertices: ", i);
    while(q != NULL){
        printf("\n\tVertex: %d",q->vertex);
        q = q->next;
    }


  }
}

#include <stdio.h>
#include <stdlib.h>
#include "../lib/stack.h"

#define MAX 20

typedef struct Node{
  struct Node *next;
  int vertex;

}node;

node *G[MAX];
int v;

void readGraph();
void insert(int a, int b);
int BSF(stack *s, int ss, int g);
void displayGraph();

int main() {
  int g ;
  stack s ;
  initialize_s(&s);
  printf("\nGive a goal state");
  scanf("%d",&g);
  readGraph();
  displayGraph();
  if(!BSF(&s, 0, g))
    printf("\nGoal state %d not found", g);
  printf("\n" );
  return 0;
}

void readGraph(){
    int i, j, e, a, b;
    printf("\nEnter the number of vertex in graph: " );
    scanf("%d",&v);
    printf("\nEnter the number of Edges: " );
    scanf("%d",&e);
    for(i=0; i<v; i++)
        G[i] = NULL;

    for ( i = 0; i < e; i++) {
      printf("\nGive the edges between(U, V) in this format(1 2): " );
      scanf("%d  %d",&a, &b);
      insert(a, b);
      //insert(b, a);
    }

}

void insert(int a, int b){
  node *p, *q;
  /*Acquire the memory for the new node and 'p' points to that memory*/
  p  = (node *)malloc(sizeof(node));
  p->next=NULL;
  p->vertex=b;
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

int BSF(stack *s, int ss, int g){
    int visited[MAX];
    int i, w;
    node *p;
    for(i=0; i< v; i++){
        visited[i] = 0;
    }
    push(ss, s);
    //printf("\nVisited vertex %d ",ss);
    visited[ss] = 1;
    while (!is_S_empty(s)) {
      ss = pop(s);
      printf("\nVisited vertex %d",ss);
      for(p = G[ss]; p != NULL; p=p->next ){
          w = p->vertex;
          if(visited[w] == 0){
              push(w, s);
              visited[w] = 1;
          }
          //if(w == g)
        //      return 1;
      }
    }
    return 1;
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

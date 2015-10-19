/*
Dijkstar's Algorithm is a single source shortest path, in which all the vertices are initially put into the priority Queue.

function Dijkstra(Graph, source):
    dist[source] ←                                     // Initialization

    create vertex set Q

    for each vertex v in Graph:
        if v ≠ source
            dist[v] ← INFINITY                          // Unknown distance from source to v
            prev[v] ← UNDEFINED                         // Predecessor of v

       Q.add_with_priority(v, dist[v])


    while Q is not empty:                              // The main loop
       u ← Q.extract_min()                            // Remove and return best vertex
       for each neighbor v of u:                       // only v that is still in Q
           alt = dist[u] + length(u, v)
           if alt < dist[v]
               dist[v] ← alt
               prev[v] ← u
               Q.decrease_priority(v, alt)

   return dist[], prev[]

* If we are only interested in a shortest path between vertices source and target:
 S ← empty sequence
 u ← target
 while prev[u] is defined:                   // Construct the shortest path with a stack S
     insert u at the beginning of S          // Push the vertex onto the stack
     u ← prev[u]                            // Traverse from target to source

*/

/*
*   UCS is a variant of Dijkstar's Algorithm for AI, in this all vertices are not insert in Queue initially.
*   Only the first source node is inserted and step by step other discovered is inserted.

procedure UniformCostSearch(Graph, start, goal)
  node ← start
  cost ← 0
  frontier ← priority queue containing node only
  explored ← empty set
  do
    if frontier is empty
      return failure
    node ← frontier.pop()
    if node is goal
      return solution
    explored.add(node)
    for each of node's neighbors n
      if n is not in explored
        if n is not in frontier
          frontier.add(n)
        else if n is in frontier with higher cost
          replace existing node with n
*/

/*More Docs are avalible in docs folder*/

#include <stdio.h>
#include <stdlib.h>
#include "../lib/minPriorityQ.c"
#define MAX 20

int v;
#include "../lib/graph.h"
BST *insert_in_set(BST *set, int pi, int v, int d);
void tracePath(BST *T, BST *set, int s, int g);
int c=0;

int main(){
    int s, g, pi, vv, d, zzz;
    BST *pq = NULL;
    BST *set = NULL;
    BST *tmp = NULL;
    node *p;
    printf("\nGive start state and goal state in this format(0 5)");
    scanf("%d %d",&s, &g );
    readGraph();
    displayGraph();
    pq = insert(pq, -1, 0, 0);
    while(1){
        if(pq == NULL){
            printf("\nPath not found!");
            break;
        }
        tmp = find_min(pq);
        pi = tmp->pi; vv = tmp->v; d = tmp->d;
        printf("\nMinimum of PQ is %d",tmp->d );
        pq = delete(pq, vv, d);
        if(vv == g){
            set  = insert_in_set(set, pi, vv, d);
            printf("\n################################# Goal found ##########################");
            tracePath(tmp, set, s, g);
            route(set);
            break;
        }
        set  = insert_in_set(set, pi, vv, d);
        for (p = G[vv]; p != NULL; p = p->next){
            if(find_set(set, p->vertex) == NULL ){
                if(find_pq(pq, p->vertex, p->d) == NULL){
                    printf("\n%d not in set" , p->vertex);
                    pq = insert(pq, vv, p->vertex, p->d);
                }
            }
        }
        //scanf("%d\n",&zzz);
        printf("\n##################################### Priority Queue is: " );
        inorder(pq);
        printf("\n##################################### Set is:");
        inorder(set);

    }

    printf("\n");
    return 0;
}

BST *insert_in_set(BST *set, int pi, int vv, int d){
    if(find_set(set, vv) == NULL){
        printf("\nNot found so inserting in set\n" );
        return insert(set, pi, d, vv); //Made this tree with vertex as branch
    }
    else
        return set;
}

void tracePath(BST *n, BST *set, int s, int g){
    int pi, vv, d;
    /*
    printf("\nThe optimal path is " );
    printf("\n==> %d", n->v);
    pi = n->pi;
    vv = n->v;
    d = n->d;
    c = d;
    */
    //printf("\nv: %d, pi: %d, d: %d, s: %d",vv, pi, d, s );
    printf("\n\n" );
    n = find_set(set, g);
    while(1){

        pi = n->pi;
        vv = n->v;
        d = n->d;
        c = c + vv;
        printf("==> %d\t", d);
        n = find_set(set, pi);
        if (n == NULL) break;
        //printf("\nv: %d, pi: %d, d: %d, s: %d",d, pi, vv, s );
        //set = delete(set, n->d, n->v);
    }

    printf("\nTotal cost from %d to %d is ==> %d\n",s, g , c);
}

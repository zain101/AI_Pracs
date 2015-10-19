/*#include <stdio.h>
#include <stdlib.h>*/

typedef struct BSTNode{
    int pi;
    int v;
    int d;
    struct BSTNode *left;
    struct BSTNode *right;
}BST;

BST *intitlize();
BST *find_set(BST *root, int v);
BST *find_pq(BST *root, int v, int d);
BST *insert(BST *root, int pi, int v, int d);
BST *makeEmpty(BST *root);
BST *find_min(BST *root);
BST *find_max(BST *root);
BST *create();
BST *delete(BST *root, int v, int d);
void inorder(BST *root);
void route(BST *root);
/*
int main(){
    BST *tmp = NULL;
    BST *root = intitlize();
    root = create();
    tmp = find_min(root);
    printf("\nMin==> distance:  %d, vertex: %d, parent: %d", tmp->d, tmp->v, tmp->pi);
    tmp = find_max(root);
    printf("\nMin==> distance:  %d, vertex: %d, parent: %d", tmp->d, tmp->v, tmp->pi);
    inorder(root);
    delete(root, 0, 0 );
    inorder(root);
    printf("\n" );
    return 0;
}

*/
BST *intitlize(){
    return NULL;
}
BST *find_set(BST *root, int v){
    while(root != NULL){
        if (root->d == v ){
            return root;
        }
        if (root->d > v)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
BST *find_pq(BST *root, int v, int d){
    while(root != NULL){
        if (root->v == v && root->d == d )
            return root;
        if (root->d > d)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

BST *insert(BST *root, int pi, int v, int d){
    BST *p, *q, *r;
    p = (BST *)malloc(sizeof(BST));
    p->left = NULL;
    p->right = NULL;
    p->pi = pi;
    p->v = v;
    p->d = d;
    if(root == NULL){
        return p;
    }
    /*Finding the leaf node*/
    r = root;

    while(r!=NULL){
        q = r;
        if(d > r->d)
            r = r->right;
        else
            r = r->left;
    }
    if(d > q->d)
        q->right = p;
    else
        q->left = p;
    return root;

}

BST *makeEmpty(BST *root){
    if(root != NULL){
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
    return(NULL);
}

BST *delete(BST *root, int v, int d){
    BST *tmp;
    if(root == NULL){
        printf("\nElement not found");
        return NULL;
    }

    if(d > root->d && root->v != v){
        //Go into right subtree.
        root->right = delete(root->right, v, d );
        return root;
    }

    if(d < root->d && root->v != v){
        //Go into left subtree
        root->left = delete(root->left, v, d);
        return root;
    }

    if(root->left == NULL && root->right == NULL){
        //Its is a leaf node.
        tmp = root;
        free(tmp);
        return NULL;
    }
    if(root->left == NULL){
        tmp = root;
        root = root->right;
        free(tmp);
        return root;
    }
    if(root->right == NULL){
        tmp = root;
        root = root->left;
        free(tmp);
        return root;
    }
    tmp = find_min(root->right);
    root->d = tmp->d;
    root->v = tmp->v;
    root->pi  = tmp->pi;
    root->right = delete(root->right, tmp->v, tmp->d);
    return root;
}

BST *find_min(BST *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

BST *find_max(BST *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

BST *create(){
    int i, n, d, v, pi;
    BST *root;
    root = NULL;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n );
    for(i=0; i<n; i++ ){
        printf("\nEnter the different tree values for #%d", i);
        printf("\nEnter the vertex no: ");
        scanf("%d", &v);
        printf("\nEnter its predessor: ");
        scanf("%d",&pi );
        printf("\nEnter the distance: ");
        scanf("%d", &d);
        root = insert(root, pi, v, d);
    }
    return root;
}

void inorder(BST *root){
    if(root != NULL){
        inorder(root->left);
        printf("%5d ",root->d );
        inorder(root->right);
    }
}

void route(BST *root){
    if(root != NULL){
        route(root->left);
        printf("\n| v = %2d pi = %2d d = %2d |",root->d, root->pi, root->v );
        route(root->right);
    }
}

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left , *right;
}Node;

Node *makenode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->left = NULL;temp->right = NULL;
    temp->data = val;
    return temp;
}

int height(Node *t)
{
    if(!t) return 0;
    int l = height(t->left);
    int r = height(t->right);
    return (l>r) ? l+1 : r+1 ;
    
}

int balance(Node *t)
{
    if(!t ) return 0;
    
    return (height(t->left) - height(t->right)) ;
}

Node *rotateleft(Node *t)
{
    Node *x = t->right ;
    Node *xr = x->left ;
    
    x->left = t;
    t->right = xr;
    return x;
}
Node *rotateright(Node *t)
{
    Node *x = t->left ;
    Node *xr = x->right ;
    
    x->right = t ;
    t->left = xr ;
    return x; 
}
Node *insertAVL(Node *l,int val)
{
    if(l==NULL) return makenode(val);
    
    if(val < l->data )
    {
        l->left =  insertAVL(l->left,val);
    }
    else if(val > l->data)
    {
        l->right  =  insertAVL(l->right,val);
    }
    else
    return l;
    
    int bf = balance(l);
    
    if(bf > 1 && val < l->left->data)
    {
        return rotateright(l);
    }
    else if(bf < -1 && val > l ->right->data)
    {
        return rotateleft(l);
    }
    else if(bf > 1 && val > l->left -> data)
    {
        l->left = rotateleft(l->left);
        return rotateright(l) ;
    }
    else if(bf < -1 && val < l-> right -> data)
    {
        l -> right = rotateright(l->right);
        return rotateleft(l);
    }
    else
    return l ;
    
}
Node *insertBST(Node *t, int data)
{
    if (t == NULL)
        return(makenode(data));

    if (data < t->data)
        t->left = insertBST(t->left, data);

    else if (data > t->data)
        t->right = insertBST(t->right, data);

    return t;
}
void inorder(Node *n)
{
    if(n!=NULL){
    inorder(n->left);
    printf("%d\t",n->data);
    inorder(n->right);
}
}


int main()
{
    Node *N1 = NULL , *N2 = NULL;
    
    for(int i =0 ; i<100 ;i++)
    {
        int data = rand()%100;
        N1 = insertAVL(N1,data);
        N2 = insertBST(N2,data);
    }  
        printf("height of the AVL tree : %d\n",height(N1));
        printf("height of the BST tree : %d\n",height(N2));
    printf("\nAVL Inorder: ");
    inorder(N1);

    printf("\nBST Inorder: ");
    inorder(N2);


    
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

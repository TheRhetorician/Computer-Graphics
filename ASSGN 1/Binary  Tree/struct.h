//Structure of a node of the Binary Tree

typedef struct node 
{ 
	int data; 
	int height;
	int c[2];
	struct node *left; 
	struct node *right; 
}node;

//Creates a tree based of on the given inputs

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
	return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->height=1;
    p->c[0]=0;
    p->c[1]=0;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}


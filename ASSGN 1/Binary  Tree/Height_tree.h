int h=1;
int arr[100]={0};
int counter=0;
int min = 100;


//Finds the height of the tree 

int maxDepth(node *node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

//Gives height of each node

void giveheight(node *root,int y)
{
	root->height = y;
	if(root->left!=NULL)
	giveheight(root->left,y-1);
	if(root->right!=NULL)
	giveheight(root->right,y-1);
}

//Gives the x and y coordinates of each node


void giveCoord(node *root,int y,int x,int w)
{
	root->c[1]=y;
	double km = pow(2,y-1);
	int q = (int) km;
	if(w==1)
	root->c[0]= x+q;
	else if(w==-1)
	root->c[0]= x-q;
	if(root->left!=NULL)
	{
		giveCoord(root->left,y-1,root->c[0],-1);
	}
	if(root->right!=NULL)
	{
		giveCoord(root->right,y-1,root->c[0],1);
	}
	
	root->c[1]=2.5*y;
}


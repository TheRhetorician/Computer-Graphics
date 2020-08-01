//Finds the minimum x coordinate of the tree 
void findmin(node *root)
{
	if(root->c[0]<min)
	min=root->c[0];
	if(root->left!=NULL)
	findmin(root->left);
	if(root->right!=NULL)
	findmin(root->right);
}

//Shifts each node by the difference between the minimum node and 1 

void shift(node *root)
{
	root->c[0]-=min;
	root->c[0]+=1;
	if(root->left!=NULL)
	shift(root->left);
	if(root->right!=NULL)
	shift(root->right);
}

//Gives the coordinates of each and every node 

void print(node *root)
{
	printf("%d %d %d\n",root->data,root->c[0],root->c[1]);
	if(root->left!=NULL)
	print(root->left);
	if(root->right!=NULL)
	print(root->right);
}


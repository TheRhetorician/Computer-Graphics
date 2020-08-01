//Finds leftmost node in the right subtree

int findLeft(node* root)
{
	node* temp = NULL;

	if(root->left!=NULL)
	{
		temp = root->left;
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}	
	}	
	if(temp!=NULL)
		return temp->c[0];
	return -1;	
}

//Finds rightmost node in the left subtree

int findRight(node* root)
{
	node* temp = NULL;
	
	if(root->right!=NULL){
		temp = root->right;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
}
	if(temp!=NULL)
		return temp->c[0];
	return -1;	
}

//Shifts all nodes of right subtree by the computed left Value

void shiftLeft(int shift,node* root)
{
	root->c[0]+=shift;
	if(root->left!=NULL)
		shiftLeft(shift,root->left);
	if(root->right!=NULL)
		shiftLeft(shift,root->right);	
}

//Shifts all nodes of left subtree by the computed right Value

void shiftRight(int shift,node* root)
{
	root->c[0]-=shift;
	if(root->left!=NULL)
		shiftRight(shift,root->left);
	if(root->right!=NULL)
		shiftRight(shift,root->right);	
}

//Shift nodes to make the Binary tree as narrow as possible

void shiftNode(int shift,node* root)
{
	if(root->left!=NULL)
		shiftLeft(shift,root->left);
	if(root->right!=NULL)	
		shiftRight(shift,root->right);
}

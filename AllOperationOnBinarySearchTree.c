#include <stdio.h> 
#include <conio.h> 
#include <malloc.h> 
#include<stdlib.h>
struct node { 
	int data; 
	struct node *left; 
	struct node *right; 
}; 
struct node *root; 
void create_tree(struct node *); 
struct node *insert(struct node *, int); 
void preorderTraversal(struct node *); 
void inorderTraversal(struct node *);
void postorderTraversal(struct node *); 
struct node *findSmallestNode(struct node *); 
struct node *findLargestNode(struct node *); 
struct node *deleteNode(struct node *, int);  
int totalNodes(struct node *); 
int heightOfTree(struct node *); 
struct node *deleteTree(struct node *); 
int main() { 
	int choice, data; 
	struct node *temp; 
	create_tree(root); 
	do {  
		printf("\n ******MAIN MENU******* \n");  
		printf("\n 1. Insert Element");  
		printf("\n 2. Preorder Traversal");  
		printf("\n 3. Inorder Traversal");  
		printf("\n 4. Postorder Traversal");  
		printf("\n 5. Find the smallest element");  
		printf("\n 6. Find the largest element");  
		printf("\n 7. Delete an element");  
		printf("\n 8. Count the total number of nodes");  
		printf("\n 9. Find the height of the tree");    
		printf("\n 10. Delete the tree");  
		printf("\n 11. Exit");  
		printf("\n\n Enter your option : ");  
		scanf("%d", &choice);  
		switch(choice)  {   
			case 1:    
				printf("\n Enter the value of the new node : ");    
				scanf("%d", &data);    
				root=insert(root,data);    
				break;   
			case 2:    
				printf("\n The elements of the tree are : \n");    
				preorderTraversal(root);    
				break;   
			case 3:    
				printf("\n The elements of the tree are : \n");    
				inorderTraversal(root);    
				break;   
			case 4:    
				printf("\n The elements of the tree are : \n");    
				postorderTraversal(root);    
				break;   
			case 5:    
				temp = findSmallestNode(root);    
				printf("\n Smallest element is :%d",temp->data);    
				break;   
			case 6:    
				temp = findLargestNode(root);    
				printf("\n Largest element is : %d", temp->data);    
				break;   
			case 7:    
				printf("\n Enter the element to be deleted : ");    
				scanf("%d", &data);
				root = deleteNode(root, data);  
				break;   
			case 8:    
				printf("\n Total no. of nodes = %d", totalNodes(root));    
				break;   
			case 9:    
				printf("\n The height of the tree = %d",heightOfTree(root));    
				break;   
			case 10:    
				root = deleteTree(root);    
				break;
			case 11:    
				exit(1); 
			default:
				printf("Invalid Choice");
			} 
		}while(1); 
		getch(); 
		return 0;
	} 
//creating Tree
void create_tree(struct node *root) { 
	root = NULL; 
} 

//function To Insert Eliment In Tree
struct node* insert(struct node *root, int data) { 
	struct node *temp, *nodePos, *parentNode; 
	temp = (struct node*)malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 
	if(root==NULL) {  
		root=temp;  
		root->left=NULL;  
		root->right=NULL;
	} 
	else {  
		parentNode=NULL;  
		nodePos=root;  
		while(nodePos!=NULL)  {   
			parentNode=nodePos;   
			if(data<nodePos->data)    
				nodePos=nodePos->left;   
			else    
				nodePos = nodePos->right;  
		}  
		if(data<parentNode->data)   
			parentNode->left = temp;  
		else   
			parentNode->right = temp; 
	} 
	return root; 
} 

//function to travers Tree(preorder)
void preorderTraversal(struct node *root) {
	if(root != NULL) {  
		printf("%d\t", root->data); 
		preorderTraversal(root->left);  
		preorderTraversal(root->right); 
	}
}

//function to travers Tree(inorder)
void inorderTraversal(struct node *root) { 
	if(root != NULL) {  
		inorderTraversal(root->left);  
		printf("%d\t", root->data);  
		inorderTraversal(root->right); 
	}
} 

//function to travers Tree(postorder)
void postorderTraversal(struct node *root) { 
	if(root != NULL) {  
		postorderTraversal(root->left);  
		postorderTraversal(root->right);  
		printf("%d\t", root->data); 
	} 
} 

//Function To Find Smallest Node In Tree
struct node *findSmallestNode(struct node *root) { 
	if( (root == NULL) || (root->left == NULL))  
		return root; 
	else  
		return findSmallestNode(root ->left); 
} 

//Function To Find Largest Node In Tree
struct node *findLargestNode(struct node *root) { 
	if( (root == NULL) || (root->right == NULL))  
		return root; 
	else  
		return findLargestNode(root->right); 
} 

//function To Delete Node From The Tree
struct node *deleteNode(struct node *root, int data) { 
	struct node *cur, *parent, *suc, *psuc, *ptr; 
	if(root->left==NULL) {  
		printf("\n The tree is empty ");  
			return(root); 
	} 
	parent = root; 
	cur = root->left; 
	while(cur!=NULL && data!= cur->data) {  
		parent = cur;  
		cur = (data<cur->data)? cur->left:cur->right; 
	} 
	if(cur == NULL) {  
		printf("\n The value to be deleted is not present in the tree");  
		return(root);  
	} 
	if(cur->left == NULL)  
		ptr = cur->right; 
	else if(cur->right == NULL)
		ptr = cur->left; 
	else {  // Find the in–order successor and its parent  
		psuc = cur;  
		cur = cur->left;  
		while(suc->left!=NULL)  {   
			psuc = suc;   
			suc = suc->left;  
		}  
		if(cur==psuc)  {   // Situation 1   
			suc->left = cur->right;  
		}  
		else  {   // Situation 2   
			suc->left = cur->left;   
			psuc->left = suc->right;   
			suc->right = cur->right;  
		}  
		ptr = suc; 
	} // Attach ptr to the parent node 
	if(parent->left == cur)  
		parent->left=ptr; 
	else  parent->right=ptr; 
	free(cur); 
	return root; 
} 

//function to count Total Node
int totalNodes(struct node *root) { 
	if(root==NULL)  
		return 0; 
	else  
		return(totalNodes(root->left) + totalNodes(root->right) + 1); 
} 

//function To Find Height Of Tree
int heightOfTree(struct node *root) { 
	int leftheight, rightheight;
	if(root==NULL)  
		return 0; 
	else {  
		leftheight = heightOfTree(root->left);  
		rightheight = heightOfTree(root->right);  
		if(leftheight > rightheight)   
			return (leftheight + 1);  
		else   
			return (rightheight + 1); 
	} 
} 

//Function To Delete Tree
struct node *deleteTree(struct node *root) { 
	if(root!=NULL) {  
		deleteTree(root->left);  
		deleteTree(root->right);  
		free(root); 
	} 
} 

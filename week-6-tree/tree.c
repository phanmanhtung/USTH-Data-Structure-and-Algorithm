// a) 2pts - Propose an Abstract Data Type implementation for this binary tree
// Data Type used: Linked List

// b) 7pts - Implement this data structure in C/C++ with the necessary function
// c) 1pts - Test and display the results using any order
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Binary search tree
typedef struct Tree{
	int data; 
	struct Tree* left;
	struct Tree* right;
} Tree;

// Function to create a new Node in heap
Tree* GetNewNode(int data) {
	Tree* newNode =  (Tree*)malloc(sizeof(Tree)); 
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in Tree, returns address of root node 
Tree* Insert(Tree* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else{
		root->right = Insert(root->right,data);
	}
	return root;
}

//To search an element in BST, returns true if element is found
int Search(Tree* root,int data) {
	if(root == NULL) return 0;
	else if(root->data == data) return 1;
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

// Function to print binary tree in 2D 
void print_tree(Tree *root, int space) {

	int count = 5;
	// Base case 
	if (root == NULL) return; 

	// Increase distance between levels 
	space += count; 
  
	// Process left child first 
	print_tree(root->left, space); 
  
	for (int i = count; i < space; i++) 
        printf(" "); 
	printf("%d\n", root->data); 
  
	// Process right child 
	print_tree(root->right, space); 
} 

int FindMin(Tree* root){ // idea: go left as long as it's possible
	while(root->left != NULL) { root = root->left; }
	return root->data; // most left leaf
}

int FindMax(Tree* root){ // idea: go right as long as it's possible
	if(root == NULL) { printf("Tree is emply"); return -1; }

	while(root->right != NULL) { root = root->right; }
	return root->data; // most right leaf
} 

float FindHeight(Tree * root){
	if(root==NULL){
		return -1; // maximum number of edge (in 1 branch)
	}
	return fmax(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// Depth: root -> wanted node
// Height : wanted node -> longest leaf

int main() {
	Tree* root = NULL;  // Creating an empty tree

	root = Insert(root,12);	
	root = Insert(root,6);	
	root = Insert(root,14);
	root = Insert(root,1);
	root = Insert(root,8);
	root = Insert(root,14);
	root = Insert(root,22);
	root = Insert(root,1);
	root = Insert(root,6);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,14);

	printf("Here is the tree!\n\n");
	print_tree(root, 0);
	printf("\n\nHeight of Tree: %.0f\n", FindHeight(root));
	printf("Max Value: %d\n", FindMax(root));
	printf("Min Value: %d\n", FindMin(root));

	int number;
	printf("Enter number be searched: ");
	scanf("%d",&number);
	if(Search(root,number) == 1) printf("Found\n");
	else printf("Not Found\n");	
}

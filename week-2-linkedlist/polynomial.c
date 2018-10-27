/*Exercise 2: Suppose that a polynomial function a 0 + a 1 x + a 2 x 2 + ... + a n x n
Using Linked Lists, we would like to improve the computation of this function. The
declaration of each node should be as following:
• a value stands for a constant of each term a i (i = 0, .., n)
• a degree indicates the degree of each term
• a pointer points to the next term
Implement and test the program in C using Linked List to manage this polyno-
mial function:
• add new terms, verify that the old term exists, if in the case, return the addition
between the old and new ones i.e given the polynomial function a 0 x 0 + a 1 x 1 ,
a new term is added into the function then the final term should be a total
• remove a term from the function
• enter a value for x then calculate the whole function
• display the whole function in the screen*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct polynomial{
	int cof;
	int exp;
	struct polynomial *next;
} polynomial;

polynomial* head= NULL; // head node

// insert a node at the beginning
void Insert(int cof_i, int exp_i){
	// fistly, we want to insert data in the list - using malloc(sizeof(Node))
	polynomial *temp = (polynomial*) malloc(sizeof(polynomial)); // 'temp' is the name of the next pointer to the new block
	
	// add value to the next node: de-referencing it to modify the value
	temp->cof = cof_i;
	temp->exp = exp_i;
	temp->next = NULL; // 2nd and still the last

	if(head != NULL) (temp)->next = head;
	head = temp;
	
	// write the address of newly created node in head
	head = temp;
}

// function to swap data of two nodes a and b
void swap(polynomial *a, polynomial *b) 
{ 
    int temp = a->cof; 
    a->cof = b->cof; 
    b->cof = temp;

int temp2 = a->exp; 
    a->exp = b->exp; 
    b->exp = temp2;  
} 

// Bubble sort the given linked list
void bubbleSort(polynomial *head){ 
	int swapped, i; 
	polynomial *p; 
	polynomial *last = NULL; 
  
    // Checking for empty list
	if (head == NULL) 
		return; 
  
	do{ 
		swapped = 0; p = head; 
	while (p->next != last) { 
		if (p->exp > p->next->exp){  
                swap(p, p->next); 
                swapped = 1; } 
        p = p->next; 
        } 
        last = p; } 
   	while(swapped); 
} 

// delete a term at position n
void Remove(int n){
	polynomial*temp1 = head;
	if(n==1){
		head = temp1->next; // head point to the second node
		free(temp1); return;
	}
	int i;
	for(i=1;i<n-1;i++) temp1 = temp1->next; // temp1 points to (n-1)th Node
	polynomial* temp2 = temp1->next; // nth Node
	temp1->next = temp2->next; // (n+1) Node -> Link is fixed
	free(temp2);
}
void Print(){

	polynomial* temp = head;
	printf("Your polynomial is: f(x) = ");
	
	const char *plus = "";
	// traverse the Linked List
	while(temp != NULL){
		bubbleSort(head); // Sort the list before displaying
		
		printf("%s%dx^%d", plus , temp->cof, temp->exp);
		plus = " + ";
		// keep going to the next node
		temp = temp->next;

	}
	printf("\n");
}

void Calculation(float x){
	float sum = 0;
	polynomial* temp = head;

	// traverse the Linked List
	while(temp != NULL){
		sum = sum + temp->cof*pow(x, (temp->exp));
		// keep going to the next node
		temp = temp->next;

	}
	printf("f(x) = %.2f\n", sum);
}

void main(){
	printf("This is a program written to handle polynomials\n");
	int test = 1;

	printf("\nDo you want to add term to your polynomial? (yes - 1,no - 0)\n");
	scanf("%d", &test);
	while(test == 1){
		int cof, exp;
		printf("Enter the coefficient: ");
		scanf("%d", &cof);
		
		printf("Enter the exponential: ");
		scanf("%d", &exp);
		Insert(cof, exp);
		
		Print();

		printf("\nDo you want to add term to your polynomial? (yes - 1,no - 0)\n");
		scanf("%d", &test);		
	}
	Print();
	test = 1;
	 
	printf("\nDo you want to remove any term from your polynomial? (yes - 1,no - 0)\n");
	scanf("%d", &test);
	while(test == 1){
		int position;
		printf("Enter the position of term you want to remove: ");
		scanf("%d", &position);
		Remove(position);

		Print();

		printf("\nDo you want to remove any term from your polynomial? (yes - 1,no - 0)\n");
		scanf("%d", &test);		
	}
	Print();
	
	printf("\nEnter value of x to calculate f(x): ");
	float x;
	scanf("%f", &x);
	Calculation(x);
}


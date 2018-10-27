/*Exercise 2:
Write a recursive function in C/C++ that calculate the sum of all elements in a
Linked List.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* link;
} Node;

Node* head= NULL;
int sum;

// insert a node at the beginning
void Insert(int x){
	Node *temp = (Node*) malloc(sizeof(Node));
	temp->data = x;
	temp->link = NULL;
	if(head != NULL) (temp)->link = head;
	head = temp;
}

void Print(){
	Node* temp = head;
	printf("List is: ");

	// traverse the Linked List
	while(temp != NULL){
		printf(" %d",temp->data);

		// keep going to the next node
		temp = temp->link;
	}
	printf("\n");
}

void Sum(Node *p){

	if(p == NULL){ printf("The sum is: %d ",sum); return;} // exit condition
	
	sum = sum + p->data;
	Sum(p->link); // Recursion call
}

int main(){
	head = NULL; // empty list
	Insert(4); // 4
	Insert(5); // 5 4
	Insert(2); // 2 5 4
	Insert(12);
	Insert(1);
	Insert(4); // 4 8 12 2 5 4
	Print();
	Sum(head);
}

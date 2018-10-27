/*Exercise 3:
Write a program in C/C++ to solve the Hanoi tower using Stacks with the Linked
List implementation. The mission is to move all the disks to some another tower
without violating the sequence of arrangement and with few rules as following:
• Only one disk can be moved among the towers at any given time.
• Only the top disk can be removed.
• No large disk can be put over a small disk.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
	char name[30];
	int data;
	struct Stack* link;
} Stack;

Stack*from = NULL; // stack is empty
Stack*to = NULL;
Stack*spare = NULL;

void Push(Stack *p,int x){
	Stack *temp=(Stack *)malloc(sizeof(Stack));

 	temp->data=x;
 	temp->link=p->link;
 	p->link=temp;
}

void Pop(Stack *p){ // delete at the beginning
  	Stack *temp=p->link;

	// delete: setting address of second to the third node
 	p->link=p->link->link;
 	free(temp);
}

int Top(Stack *p) { return p->link->data; }

void Print(Stack *temp){
	Stack *p = temp->link;
	printf("%s: ", temp->name);

	// traverse the Linked List
	while(p != NULL){
		printf(" %d",p->data);
		// keep going to the next node
		p = p->link;
	}
	printf("\n");
}

void Display(){
	Print(from);
	Print(spare);
	Print(to);
	printf("\n");
}

void Towers(int n, Stack*fr, Stack*to, Stack*spare){
    if(n == 1){ // base case
	Push(to, Top(fr));
	Pop(fr);
	Display();
	return;

    }else{ // think recursively
        Towers(n-1, fr, spare, to); // solve a smaller problem

        Push(to, Top(fr)); // solve a basic problem
	Pop(fr);
	Display();

        Towers(n-1, spare, to, fr); // solve a smaller problem
    }
}

void main(){
	from=(Stack*)malloc(sizeof(Stack)); // create dynamic memory for the stack
	to=(Stack*)malloc(sizeof(Stack));
	spare=(Stack*)malloc(sizeof(Stack));

	strcpy(from->name, "From");
	strcpy(to->name, "To");
	strcpy(spare->name, "Spare");
  	
	int i, n;
	printf("Tower of Hanoi!\n");
	printf("Enter number of disks you want to move: ");
	scanf("%d", &n);
	printf("\n");
	
	for(i=n;i>=1;i--){ Push(from, i); }
	
	Display();
	Towers(n, from, to, spare);	
}


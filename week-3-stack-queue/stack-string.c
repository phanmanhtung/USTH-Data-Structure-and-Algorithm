/*Exercise 1:
Write a program in C/C++ to enter a string of characters i.e. your name, then try
to compute this string in reverse order using a Stack structure with the Linked List
principle.
For example: ”Nguyen Van A” → ”A Nav Neyugn”*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
	char c;
	struct Stack* link;
} Stack;

Stack* top= NULL; // head(top) node
// top address -> NULL: initially, my stack is empty

void Push(char x){ // insert at the beginning
	Stack *temp = (Stack*) malloc(sizeof(Stack));
	
	temp->c = x; 
	temp->link = top;
	top = temp;
}


void Print(){
	Stack* temp = top;
	printf("String in reverse is: ");

	while(temp != NULL){
		printf("%c", temp->c);
		temp = temp->link;
	}
	printf("\n");
}


int main(){
	char c[51];
	printf("Enter a string: ");
	fgets(c, 51, stdin);
	int i;
	for(i=0;i<strlen(c);i++){ Push(c[i]); };

	Print();
}





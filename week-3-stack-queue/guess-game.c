/*Exercise 3:
Suppose that we play a following game. There are a list 10 numbers from 0 to 9
and an empty stack.
• Step 1: We draw randomly a number n 1 from the list and push it into a stack.
• Step 2: We perform randomly a second draw to choose another number n 2
from the list and put it into the stack. If n 1 == n 2 , we must draw again.
• Step 3: While the first two are still unknown. Don’t reveal these number then
guess a third number n 3 . This number is entered from keyboard.
• Step 4: Verify that the third number is between the first and the second
(n 1 < n 3 < n 2 or n 2 < n 3 < n 1 ). If true, you win.
• Step 5: Otherwise, pop up the second number from the stack. Return to the
Step 2. If we still guess wrong number this time, your turn is over and clear
the stack to play the game again.*/

#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Stack{
	int data;
	struct Stack* link;
} Stack;

Stack* top= NULL; // head(top) node
// top address -> NULL: initially, my stack is empty

void Push(int x){ // insert at the beginning
	Stack *temp = (Stack*) malloc(sizeof(Stack));
	
	temp->data = x; 
	temp->link = top;
	top = temp;
}

void Pop(){ // delete at the beginning
	Stack *temp;
	if(top == NULL) return; // check empty
	temp = top; // point the newly created note link to the top node -> in order to free it later
	
	// delete: setting address of top to the second node
	top = top->link;
	free(temp);
}

void Print(){
	Stack* temp = top;
	printf("The current stack is: ");

	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(int argc, char* argv[]){
   printf("Welcome to the game of cards!\n");
   int win = 0;
   do{	// do-while loop for replaying
	srand((unsigned)time(NULL));
	int n1 = rand()%9+1;
	Push(n1);

	int n2, k;
	for(k=0;k<10;k++){ 
		n2 = rand()%9+1;
		if(n1!=n2){Push(n2);break;} // check whether n1!=n2 to push the card or draw again	
	}
	int n3;
	printf("The first 2 cards have already drawn\n");
	printf("Try to get the value in between");
	printf("\nGuess the third number: ");
	scanf("%d", &n3);
	
	if((n1<n3 && n3<n2) || (n2<n3 && n3<n1)){ Print(); printf("\nYou won\n"); win=1; }
	else{
		Pop();	// get rid of the second card
		for(k=0;k<10;k++){	// draw again
			n2 = rand()%9+1;
			if(n1!=n2){Push(n2);break;};
		}
		int n3;
		printf("\nThe second card has redrawn\n");
		printf("Try to get the value in between");
		printf("\nGuess the third number: ");
		scanf("%d", &n3);
	
		if((n1<n3 && n3<n2) || (n2<n3 && n3<n1)){ Print(); printf("\nYou won\n"); win=1; }
		else{ Pop(); Pop(); printf("Your turn is over! Play again\n\n"); }
	}
    } while(win!=1);
}

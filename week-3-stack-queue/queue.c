/*Exercise 2:
Assume that a queue of N passengers waiting to enter a train car
• Only the first person in the queue can enter at a time
• New persons arrive will go to the end of the queue.
Implement basic operations for Queue ADT using the Linked List principle to manage the queue.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue {
	char name[30];
	struct Queue* next;
} Queue;

Queue* front = NULL;
Queue* rear = NULL; // firstly, there is nothing

// New persons arrive will go to the end of the queue
void Enqueue(char* name) {
	printf("One more person arrive. His/Her name is %s\n", name);
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	strcpy(temp->name, name);
	temp->next = NULL; // the data is in REAR
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp; // temp point to the new node 
	rear = temp; // modify the rear as the new node
}

// Only the first person in the queue can enter at a time
void Dequeue() {
	printf("The person in front enters! please!\n");
	Queue* temp = front; // create temp to store front to free later
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp); // free the old front
}

void Print(){ // just like print in Linked List
	Queue* temp = front;
	printf("Current Queue: ");
	while(temp != NULL) {
		printf("%s ",temp->name);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	Enqueue("Tung");
	Enqueue("Hoang");
	Enqueue("Thu");
	Print();
	Dequeue();
	Print();
	Enqueue("Truong");
	Print();
	Enqueue("Nam");
	Enqueue("Tu");
	Print();
	Dequeue();
	Print();
}
